/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:14:49 by bena              #+#    #+#             */
/*   Updated: 2023/02/15 05:47:20 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"
#include "length.h"

void		ft_putnbr_fd(int n, int fd);
void		set_lengths(int num, t_length *length, t_flags *flags, int base);
static void	put_sign(int num, t_flags *flags);
static void	put_paddings(t_length *length, t_flags *flags);
static void	put_precision(int count);
static void	put_nbr(int num);

int	print_dec(int num, t_flags *flags)
{
	t_length	length;

	set_lengths(num, &length, flags, 10);
	if (flags->left_align == 0 && flags->zero_padding != F_ZERO_PADDING)
		put_paddings(&length, flags);
	put_sign(num, flags);
	if (flags->left_align == 0 && flags->zero_padding == F_ZERO_PADDING)
		put_paddings(&length, flags);
	put_precision(length.precision_padding);
	if (length.value != 0)
		put_nbr(num);
	if (flags->left_align == 1)
		put_paddings(&length, flags);
	return (length.total);
}

static void	put_sign(int num, t_flags *flags)
{
	if (num < 0)
		write(1, "-", 1);
	if (flags->sign == F_SIGN_SPACE)
		write(1, " ", 1);
	if (flags->sign == F_SIGN_PLUS)
		write(1, "+", 1);
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
	while (count-- > 0)
		write(1, " ", 1);
}

static void	put_precision(int count)
{
	if (count < 1)
		return ;
	while (count-- > 0)
		write(1, "0", 1);
}

static void	put_nbr(int num)
{
	int	output;

	output = 0;
	if (num == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	ft_putnbr_fd(num, 1);
}
