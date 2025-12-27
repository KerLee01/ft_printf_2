#include "ft_printf.h"

static bool is_flag(char c, t_data *data)
{
	if(c == ' ')
		return (data->if_positive_space = true, true);
	if(c == '+')
		return (data->show_sign = true, true);
	if(c == '#')
		return (data->hex_hash = true, true);
	if(c == '-')
		return (data->left_align = true, true);
	if(c == '0')
		return(data->width_padding = '0', true);
	return false;
}

static bool is_specifier(char s)
{
	if(s == 'c' || s == 's' || s == 'p' || s == 'd' || s == 'i' || s == 'u' ||
			s == 'x' || s == 'X' || s == '%')
		return true;
	return false;
}

static void set_format_data(t_data *data)
{
	data->if_positive_space = false;
	data->show_sign = false;
	data->hex_hash = false;
	data->left_align = false;
	data->precision_set = false;
	data->width_padding = ' ';
	data->precision = 0;
	data->specifier = 0;
}

static int add_number(const char **format)
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

static void process_format(const char **format, t_data *data)
{
	char *initial_format = (char *)*format;

	while(is_flag(**format, data) == true)
		(*format)++;
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
		(void)write(1, data->stash, 4096);
		data->current_byte = 0;
	}
	data->stash[(data->current_byte)++] = c;
}

static void insert_specifier_str(t_data *data, va_list *ap)
{
	if(data->specifier == 'c')
		c_handler(data, ap);
	else if(data->specifier == 's')
		s_handler(data, ap);
	else if(data->specifier == 'p')
		p_handler(data, ap);
	else if(data->specifier == 'x' || data->specifier == 'X')
		x_X_handler(data,ap);
	else if(data->specifier == 'u')
		u_handler(data, ap);
	else if(data->specifier == 'i' || data->specifier == 'd')
		i_d_handler(data, ap);
	else if(data->specifier == '%')
		check_flush_insert(data, '%');
}

static void fill_stash(const char *format, va_list *ap, t_data *data)
{
	while(*format != '\0')
	{
		if(*format == '%')
		{
			format++;
			set_format_data(data);
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
	set_format_data(&data);
	data.total_bytes = 0;
	data.current_byte = 0;

	fill_stash(format, &ap, &data);
	(void)write(1, data.stash, data.current_byte);
	data.total_bytes += data.current_byte;
	total_written = data.total_bytes;
	return (va_end(ap), total_written);
}

