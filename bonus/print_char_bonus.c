/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:26:20 by bena              #+#    #+#             */
/*   Updated: 2023/02/22 05:29:51 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags_bonus.h"

void		*ft_memset(void *b, int c, size_t len);
int			ft_atoi(const char *str);
void		set_flags(const char c, t_flags *flags);
int			is_flag_character(const char c);
static int	put_result(char c, t_flags *flags);

int	print_char(char c, const char *ptr)
{
	t_flags	flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	while (is_flag_character(*(++ptr)))
		set_flags(*ptr, &flags);
	flags.width = ft_atoi(ptr);
	return (put_result(c, &flags));
}

static int	put_result(char c, t_flags *flags)
{
	int	output;

	if (flags->width == 0)
		flags->width = 1;
	output = (flags->width)--;
	if (flags->left_align == 0)
		while ((flags->width)-- > 0)
			write(1, " ", 1);
	write(1, &c, 1);
	if (flags->left_align == 1)
		while ((flags->width)-- > 0)
			write(1, " ", 1);
	if (output < 1)
		return (1);
	return (output);
}
