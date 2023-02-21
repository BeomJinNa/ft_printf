/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:14:30 by bena              #+#    #+#             */
/*   Updated: 2023/02/22 05:30:31 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags_bonus.h"

void		*ft_memset(void *b, int c, size_t len);
int			ft_atoi(const char *str);
void		set_flags(const char c, t_flags *flags);
int			is_flag_character(const char c);
static int	print_address(void *address, t_flags *flags);
size_t		digit_of_address(unsigned long long num);
size_t		max_len(size_t a, size_t b);
void		put_address(unsigned long long num);

int	print_ptr(void *address, const char *ptr)
{
	t_flags	flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	while (is_flag_character(*(++ptr)))
		set_flags(*ptr, &flags);
	flags.width = ft_atoi(ptr);
	return (print_address(address, &flags));
}

static int	print_address(void *address, t_flags *flags)
{
	size_t	length;
	size_t	space;

	length = digit_of_address((unsigned long long)address) + 2;
	space = max_len(length, flags->width) - length;
	if (flags->left_align == 0)
		while (space-- > 0)
			write(1, " ", 1);
	write(1, "0x", 2);
	put_address((unsigned long long)address);
	if (flags->left_align == 1)
		while (space-- > 0)
			write(1, " ", 1);
	return (length);
}
