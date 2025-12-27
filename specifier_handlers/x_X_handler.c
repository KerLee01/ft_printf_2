#include "../ft_printf.h"

static int get_hex_length(t_data *data, unsigned long hex)
{
	int length;

	length = 0;
	if(hex == 0 && data->precision_set == true && data->precision == 0)
		return (0);
	if(hex == 0)
		return (1);
	if(data->hex_hash == true)
		length += 2;
	while(hex > 0)
	{
		length++;
		hex /= 16;
	}
	return length;
}

static void insert_hex(t_data *data, unsigned long num, int hex_length)
{
	char *base;
	
	base = "0123456789abcdef";
	if(data->specifier == 'X')
		base = "0123456789ABCDEF";
	if(hex_length == 0)
		return;
	if(num >= 16)
		insert_hex(data, num /16, hex_length);
	check_flush_insert(data, base[num % 16]);
}

void x_X_handler(t_data *data, va_list *ap)
{
	unsigned long hex;
	int hex_length;
	int width;

	hex = va_arg(*ap, unsigned int);
	width = data->width + 1;
	hex_length = get_hex_length(data, hex);
	if(data->width_padding == '0' && (data->left_align == true || data->precision_set == true))
		data->width_padding = ' ';
	while(data->left_align == false && (--(width) - hex_length) > 0)
		check_flush_insert(data, data->width_padding);
	if(data->hex_hash == true && hex != 0)
	{
		check_flush_insert(data, '0');
		if(data->specifier == 'X')
			check_flush_insert(data, 'X');
		else
			check_flush_insert(data, 'x');
	}
	precision_pad(data, (long)hex);
	insert_hex(data, hex, hex_length);
	while(data->left_align == true && (--(width) - hex_length) > 0)
			check_flush_insert(data, data->width_padding);
}
