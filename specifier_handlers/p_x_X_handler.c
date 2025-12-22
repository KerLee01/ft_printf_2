#include "ft_printf.h"

int get_hex_length(unsigned long hex)
{
	int length;

	length = 0;
	while(hex > 0)
	{
		length++;
		hex /= 16;
	}
	return (length);
}

void insert_hex(t_data *data, unsigned long num)
{
	char *base;

	if(data->specifier == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if(num >= 16)
		insert_hex(data, num /16);
	check_flush_insert(data, base[num % 16]);
}

void p_handler(t_data *data, va_list *ap)
{
	void *ptr;
	int width;
	int hex_length;
	unsigned long address;

	ptr = va_arg(*ap, void *);
	width = data->width + 3;
	address = (unsigned long)ptr;
	hex_length = get_hex_length(address);
	while(data->left_align == false && --(width) - hex_length > 0)
		check_flush_insert(data, ' ');
	check_flush_insert(data, '0');
	check_flush_insert(data, 'x');
	insert_hex(data, address);
	while(data->left_align == true && --(width) - hex_length > 0)
		check_flush_insert(data, ' ');
}

void x_X_handler(t_data *data, va_list *ap)
{
	unsigned int hex;
	int hex_length;
	int width;

	hex = va_arg(*ap, unsigned int);
	width = data->width + 1;
	hex_length = get_hex_length((unsigned long)hex);
	if(data->precision_set == true && data->precision > hex_length && data->zero_pad == true)
		data->zero_pad = false;
	if(data->zero_pad == true)
		data->width_padding = '0';
	if(data->precision > hex_length)
		hex /= data->precision;
	while(data->precision > 0 && data->left_align == false && --(width) > data->precision)
		check_flush_insert(data, data->width_padding);
	if(data->hex_hash == true)
	{
		check_flush_insert(data, '0');
		check_flush_insert(data, 'x');
	}
	insert_hex(data, hex);
	while(data->precision > 0 && data->left_align == true && --(width) > data->precision)
		check_flush_insert(data, data->width_padding);
}
