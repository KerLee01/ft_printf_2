#include "../ft_printf.h"
static void apply_width(t_data *data, char *s_string, int s_length)
{
	int i;

	i = 0;
	while(data->left_align == false && data->width - s_length > 0)
	{
		check_flush_insert(data, ' ');
		(data->width)--;
	}
	while(s_string[i] != '\0')
	{
		check_flush_insert(data, s_string[i]);
		i++;
	}
	
	while(data->left_align == true && data->width - s_length > 0)
	{
		check_flush_insert(data, ' ');
		(data->width)--;
	}
}

static void apply_width_precision(t_data *data, char *s_string)
{
	int i;

	i = 0;
	while(data->left_align == false && data->width - data->precision > 0)
	{
		check_flush_insert(data, ' ');
		(data->width)--;
	}
	while(i < data->precision)
	{
		check_flush_insert(data, s_string[i]);
		i++;
	}
	while(data->left_align == true && data->width - data->precision > 0)
	{
		check_flush_insert(data, ' ');
		(data->width)--;
	}
}

void s_handler(t_data *data, va_list *ap)
{
	char *s_string;
	int s_length;
	int i;

	s_string = va_arg(*ap, char *);
	if(s_string == NULL && data->precision_set == false)
		s_string = "(null)";
	else if(s_string == NULL && data->precision_set == true)
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
