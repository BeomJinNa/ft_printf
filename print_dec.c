/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:14:49 by bena              #+#    #+#             */
/*   Updated: 2023/02/15 03:43:21 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"
#include "length.h"

void	ft_putnbr_fd(int n, int fd);
void	set_lengths(int num, t_length *length, t_flags *flags, int base);

int	print_dec(int num, t_flags *flags)
{
	t_length	length;

	if (flags->precision == 0 && num == 0)
		return (0);
	set_lengths(num, &length, flags, 10);
}

static 
