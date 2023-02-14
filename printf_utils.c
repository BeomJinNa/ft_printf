/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:09:07 by bena              #+#    #+#             */
/*   Updated: 2023/02/15 01:06:37 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"

int	is_passable_character(const char c)
{
	if (*c != 'c' && *c != 's' && *c != 'p' && *c != 'd' && *c != 'i'
		&& *c != 'u' && *c != 'x' && *c != 'X' && *c != '%')
		return (1);
	return (0);
}

int	is_flag_character(const char c)
{
	if (*c != '-' && *c != '0' && *c != '#' && *c != ' ' && *c != '+')
		return (1);
	return (0);
}

void	set_flags(const char c, t_flags *flags)
{
	if (c == '-')
	{
		flags->left_align = 1;
		flags->zero_padding = F_NO_PADDING;
	}
	if (c == '0')
		flags->zero_padding = F_ZERO_PADDING;
	if (c == '#')
		flags->base_visable = 1;
	if (c == ' ')
		flags->sign = SIGN_SPACE;
	if (c == '+')
		flags->sign = SIGN_PLUS;
}

size_t	min_len(size_t a, size_t b)
{
	if (a >= b)
		return (b);
	return (a);
}

void	ft_putstrn(char *s, size_t buffer)
{
	char	*ptr;

	ptr = s;
	while (*ptr && ptr - s < buffer)
		ptr++;
	write(1, s, ptr - s);
}
