#include "../ft_printf_bonus.h"

static int ft_strlen(char *str)
{
	int i;

	i = 0;
	if(!str)
		return (0);
	while(str[i] != '\0')
		i++;
	return i;
}

static void apply_width(t_data *data, char *s_string, int s_length)
{
	int i;
	int width;

	i = -1;
	width = data->width + 1;
	while(data->left_align == false && --width - s_length > 0)
		check_flush_insert(data, ' ');
	while(s_string[++i] != '\0')
		check_flush_insert(data, s_string[i]);
	while(data->left_align == true && --width - s_length > 0)
		check_flush_insert(data, ' ');
}

static void apply_width_precision(t_data *data, char *s_string)
{
	int i;
	int width;

	i = 0;
	width = data->width + 1;
	while(data->left_align == false && --width - data->precision > 0)
		check_flush_insert(data, ' ');
	while(++i < data->precision)
		check_flush_insert(data, s_string[i]);
	while(data->left_align == true && --width - data->precision > 0)
		check_flush_insert(data, ' ');
}

void s_handler(t_data *data, va_list *ap)
{
	char *s_string;
	int s_length;
	int i;

	s_string = va_arg(*ap, char *);
	if(s_string == NULL && (data->precision_set == false || data->precision >= 6))
		s_string = "(null)";
	else if(s_string == NULL && data->precision_set == true && data->precision < 7)
		s_string = "";
	s_length = ft_strlen(s_string);
	i = -1;
	if(data->precision >= s_length)
		data->precision_set = false;
	else if(data->precision_set == true)
		s_length = data->precision;
	if(data->width - s_length <= 0)
		data->width = 0;
	while(data->precision_set == false && data->width == 0 && s_string[++i] != '\0')
		check_flush_insert(data, s_string[i]);
	while(data->width == 0 && data->precision == s_length && ++i < data->precision)
		check_flush_insert(data, s_string[i]);
	if(data->precision_set == false && data->width - s_length > 0)
		apply_width(data, s_string, s_length);
	if(data->width > data->precision && data->precision == s_length)
		apply_width_precision(data, s_string);
}
