/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:38:06 by bena              #+#    #+#             */
/*   Updated: 2023/02/15 04:59:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"
#include "length.h"

int	is_there_sign(int num, t_flags *flags);

size_t	min_len(size_t a, size_t b)
{
	if (a >= b)
		return (b);
	return (a);
}

size_t	max_len(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	ft_putstrn(char *s, size_t buffer)
{
	char	*ptr;

	ptr = s;
	while (*ptr && ptr - s < buffer)
		ptr++;
	write(1, s, ptr - s);
}

size_t	digit_of_number(long long num, int base)
{
	long long	dummy;
	size_t		digit;

	if (base < 2)
		return (0);
	dummy = base;
	digit = 1;
	if (num < 0)
		num = -num;
	while (dummy - 1 < num)
	{
		dummy *= base;
		digit++;
		if (dummy > 2147483647)
			return (0);
	}
	return (digit);
}

void	set_lengths(int num, t_length *length, t_flags *flags, int base)
{
	length->value = digit_of_number((long long)num, base);
	if (num == 0 && flags->zero_padding == F_ZERO_PRECISION)
		length->value = 0;
	length->precision_padding = 0;
	if (flags->precision > length->value)
		length->precision_padding = flags->precision - length->value;
	length->number = max_len(flags->precision, length->value);
	length->number += is_there_sign(num, flags);
	length->total = max_len(flags->width, length->number);
	length->space = length->total - length->number;
}
