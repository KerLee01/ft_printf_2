/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:49:14 by kerlee            #+#    #+#             */
/*   Updated: 2026/01/15 17:49:16 by kerlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	precision_pad(t_data *data, long num)
{
	int	length;
	int	precision;
	int	hex_or_int;

	length = 0;
	precision = data->precision + 1;
	hex_or_int = 10;
	if (data->specifier == 'x' || data->specifier == 'X')
		hex_or_int = 16;
	if (num < 0)
		num *= -1;
	if (num == 0)
		length = 1;
	while (num > 0)
	{
		length++;
		num /= hex_or_int;
	}
	while (data->precision_set == true && (--precision - length) > 0)
		check_flush_insert(data, '0');
}
