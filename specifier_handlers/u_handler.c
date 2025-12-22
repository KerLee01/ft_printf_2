#include "ft_printf.h"

int get_num_length(int num)
{
	int length;

	length = 0;
	while(num > 0)
	{
		num /= 10;
		length++;
	}
	return length;
}

void insert_num(t_data *data, int num)
{
	if(num > 10)
		insert_num(data, num / 10);

	check_flush_insert(data, num % 10 + '0');
}

void i_d_handler(t_data *data, ca_list *ap)
{
	int num;

	num = va_arg(*ap, int);
	

void u_handler(t_data *data, va_list *ap)
{
	unsigned int num;
	int width;
	int num_length;
	int precision;

	num = va_arg(*ap, unsigned int);
	width = data->width + 1;
	precision = data->precision + 1;
	num_length = get_num_length(num);
	
	if(data->precision_set == true && data->left_align == false && data->precision > 0 && data->zero_pad == true)
		data->width_padding = '0';
	while(data->left_align == false && data->precision > 0 && --(width) > data->precision)
		check_flush_insert(data, data->width_padding);
	if(--(precision) - num_length > num_length)
		check_flush_insert(data, '0');
	insert_num(data, num);
	while(data->left_align == true && data->precision > 0 && --(width) > data->precision)
		check_flush_insert(data, data->width_padding);
}



