#include "ft_printf.h"

static int get_unsigned_length(unsigned int n)
{
	int length;

	length = 0;
	if(n == 0)
		return (1);
	while(n > 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static void insert_unsigned(t_data *data, unsigned int n)
{
	if(n >= 10)
		insert_unsigned(data, n / 10);
	check_flush_insert(data, (n % 10) + '0');
}

void u_handler(t_data *data, va_list *ap)
{
	unsigned int num;
	int num_length;
	int width;

	num = va_arg(*ap, unsigned int);
	num_length = get_unsigned_length(num);
	width = data->width + 1;
	if(data->width_padding == '0' && (data->left_align == true || data->precision_set == true))
		data->width_padding = ' ';
	while(data->left_align == false && (--(width) - num_length > 0))
		check_flush_insert(data, data->width_padding);
	precision_pad(data, (long)num);
	insert_unsigned(data, num);
	while(data->left_align == true && (--(width) - num_length > 0))
		check_flush_insert(data, data->width_padding);
}
