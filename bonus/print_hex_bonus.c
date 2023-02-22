/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:14:49 by bena              #+#    #+#             */
/*   Updated: 2023/02/22 13:12:18 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags_bonus.h"
#include "length_bonus.h"

void		ft_putnbr_fd(int n, int fd);
void		set_lengths(long long num, t_length *l, t_flags *f, int base);
static void	put_sign(char conversion);
static void	put_paddings(t_length *length, t_flags *flags);
static void	put_precision(size_t count);
static void	put_hex(unsigned int num, char conversion);
void		puthex_u(unsigned int num);
void		puthex_l(unsigned int num);

int	print_hex(unsigned int num, t_flags *flags, char conversion)
{
	t_length	length;

	set_lengths((long long)num, &length, flags, 16);
	if (flags->left_align == 0 && flags->zero_padding != F_ZERO_PADDING)
		put_paddings(&length, flags);
	if (flags->base_visible == 1 && num != 0)
		put_sign(conversion);
	if (flags->left_align == 0 && flags->zero_padding == F_ZERO_PADDING)
		put_paddings(&length, flags);
	put_precision(length.precision_padding);
	if (length.value != 0)
		put_hex(num, conversion);
	if (flags->left_align == 1)
		put_paddings(&length, flags);
	return (length.total);
}

static void	put_sign(char conversion)
{
	if (conversion == 'x')
		write(1, "0x", 2);
	if (conversion == 'X')
		write(1, "0X", 2);
}

static void	put_paddings(t_length *length, t_flags *flags)
{
	size_t	count;

	if (length->space == 0)
		return ;
	count = length->space;
	if (flags->zero_padding == F_ZERO_PADDING)
		while (count-- > 0)
			write(1, "0", 1);
	if (flags->zero_padding != F_ZERO_PADDING)
		while (count-- > 0)
			write(1, " ", 1);
}

static void	put_precision(size_t count)
{
	if (count == 0)
		return ;
	while (count-- > 0)
		write(1, "0", 1);
}

static void	put_hex(unsigned int num, char conversion)
{
	if (conversion == 'x')
		puthex_l(num);
	if (conversion == 'X')
		puthex_u(num);
}
