/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:14:49 by bena              #+#    #+#             */
/*   Updated: 2023/02/22 05:30:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags_bonus.h"
#include "length_bonus.h"

void		ft_putnbr_fd(int n, int fd);
void		set_lengths(long long num, t_length *l, t_flags *f, int base);
static void	put_paddings(t_length *length, t_flags *flags);
static void	put_precision(int count);
void		put_uint(unsigned int num);

int	print_uint(unsigned int num, t_flags *flags)
{
	t_length	length;

	set_lengths(num, &length, flags, 10);
	if (flags->left_align == 0)
		put_paddings(&length, flags);
	put_precision(length.precision_padding);
	if (length.value != 0)
		put_uint(num);
	if (flags->left_align == 1)
		put_paddings(&length, flags);
	return (length.total);
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
