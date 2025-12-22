#include "ft_printf.h"

bool is_flag(char c, t_data *data)
{
	if(c == ' ')
		return (data->if_positive_space = true, true);
	if(c == '+')
		return (data->show_num_sign = true, true);
	if(c == '#')
		return (data->hex_hash = true, true);
	if(c == '-')
		return (data->left_align = true, true);
	if(c == '0')
		return(data->width_padding = '0', data->zero_pad = true, true);
	return false;
}

bool is_specifier(char s)
{
	if(s == 'c' || s == 's' || s == 'p' || s == 'd' || s == 'i' || s == 'u' ||
			s == 'x' || s == 'X' || s == '%')
		return true;
	return false;
}

int add_number(const char **format)
{
	int result;

	result = 0;
	while(**format >= '0' && **format <= '9')
	{
		result *= 10;
		result += (**format - '0');
		(*format)++;
	}
	return result;
}

void process_format(const char **format, t_data *data)
{
	char *initial_format = (char *)*format;
	int j;

	j = 0;
	while(is_flag(**format, data) == true)
	{
		(data->flag)[j] = **format;
		(j)++;
		(*format)++;
	}
	(data->flag)[data->current_byte] = '\0';
	data->width = add_number(format);
	if(**format == '.')
	{
		data->precision_set = true;
		(*format)++;
		data->precision = add_number(format);
	}
	if(is_specifier(**format) == true)
	{
		data->specifier = **format;
		(*format)++;
	}
	else
		*format = initial_format;
}

void check_flush_insert(t_data *data, char c)
{
	if(data->current_byte == STASH_SIZE)
	{
		write(1, data->stash, 4096);
		data->current_byte = 0;
	}
	data->stash[(data->current_byte)++] = c;
}

void insert_specifier_str(t_data *data, va_list *ap)
{
	if(data->specifier == 'c')
		c_handler(data, ap);
	if(data->specifier == 's')
		s_handler(data, ap);
	if(data->specifier == 'p')
		p_handler(data, ap);
	if(data->specifier == 'x' || data->specifier == 'X')
		x_X_handler(data,ap);
	if(data->specifier == 'u')
		u_handler(data, ap);
	if(data->specifier == '%')
		check_flush_insert(data, '%');
}

void fill_stash(const char *format, va_list *ap, t_data *data)
{
	while(*format != '\0')
	{
		if(*format == '%')
		{
			format++;
			process_format(&format, data);
			insert_specifier_str(data, ap);
		}
		else
		{
			check_flush_insert(data, *format);
			format++;
		}
	}
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	t_data data;
	int total_written;

	// initialise data
	data.if_positive_space = false;
	data.show_num_sign = false;
	data.hex_hash = false;
	data.left_align = false;
	data.zero_pad = false;
	data.width_padding = ' ';
	data.total_bytes = 0;
	data.current_byte = 0;
	data.width = 0;
	data.precision = 0;
	data.specifier = 0;

	fill_stash(format, &ap, &data);
	write(1, data.stash, data.current_byte);
	data.total_bytes += data.current_byte;
	total_written = data.total_bytes;
	va_end(ap);
	return (total_written);
}

