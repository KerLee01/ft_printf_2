#include "ft_printf.h"
void handle_precision_n_width(t_data *data, char *s_string)
{
	int i;
	int width;

	i = -1;
	width = data->width + 1;
	while(data->left_align == true && s_string[++i] != 0 && i < data->precision)
		check_flush_insert(data, s_string[i]);
	while(--width > data->precision)
		check_flush_insert(data, ' ');
	while(data->left_align == false && s_string[++i] != '\0' && i < data->precision)
		check_flush_insert(data, s_string[i]);
}

void handle_width(t_data *data, char *s_string, int s_length)
{
	int i;
	int width;

	i = -1;
	width = data->width + 1;
	while(data->left_align == true && s_string[++i] != '\0')
		check_flush_insert(data, s_string[i]);
	while(--width - s_length > 0)
		check_flush_insert(data, ' ');
	while(data->left_align == false && s_string[++i] != '\0')
		check_flush_insert(data, s_string[i]);
}

void s_handler(t_data *data, va_list *ap)
{
	char *s_string;
	int s_length;
	int i;

	s_string = va_arg(*ap, char *);
	s_length = ft_strlen(s_string);
	i = -1;
	if(data->precision >= s_length)
		data->precision = 0;
	else
		s_length = data->precision;
	if(data->width <= s_length)
		data->width = 0;
	while(data->precision == 0 && data->width == 0 && s_string[++i] != '\0')
		check_flush_insert(data, s_string[i]);
	if(data->precision > 0 && data->width > data->precision)
		handle_precision_n_width(data, s_string);
	while(data->precision == 0 && data->width > s_length)
		handle_width(data, s_string, s_length);
	while(data->width == 0 && data->precision > 0 && i < data->precision && s_string[++i] != '\0')
		check_flush_insert(data, s_string[i]);
}
