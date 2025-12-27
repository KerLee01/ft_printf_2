#include "ft_printf.h"

static int get_num_length(t_data *data, long num)
{
	int length;
 
	length = 0;
	if(num < 0)
	{
		num *= -1;
		length++;
	}
	else if(data->show_sign == true)
		length++;
	if(num == 0)
		return (length + 1);
	while(num > 0)
	{
		num /= 10;
		length++;
	}
	return length;
}

static void insert_num(t_data *data, long num)
{
	if(num < 0)
		num *= -1;
	if(num >= 10)
		insert_num(data, num / 10);
	check_flush_insert(data, (num % 10) + '0');
}

void i_d_handler(t_data *data, va_list *ap)
{
	int num;
	int num_length;
	int width;

	num = va_arg(*ap, int);
	width = data->width + 1;
	if(data->show_sign == true && data->if_positive_space == true)
		data->if_positive_space = false;
	if(data->width_padding == '0' && (data->precision_set == true || data->left_align == true))
		data->width_padding = ' ';
	if(num < 0)
		check_flush_insert(data, '-');
	num_length = get_num_length(data, (long)num);
	while(data->left_align == false && (--(width) - num_length) > 0)
		check_flush_insert(data, data->width_padding);
	if(data->show_sign == true && num >= 0)
		check_flush_insert(data, '+');
	if(data->if_positive_space == true && num >= 0)
		check_flush_insert(data, ' ');
	precision_pad(data, (long)num);
	insert_num(data, (long)num);
	while(data->left_align == true && (--(width) - num_length) > 0)
		check_flush_insert(data, data->width_padding);
}
