/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:14:30 by bena              #+#    #+#             */
/*   Updated: 2023/02/15 07:42:51 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"

void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(const char *str);
void	set_flags(const char c, t_flags *flags);
int		is_flag_character(const char c);
int		print_dec(int num, t_flags *flags);
int		print_hex(int num, t_flags *flags, char conversion);
int		print_uint(unsigned int num, t_flags *flags);

int	print_int(int num, const char *ptr, char conversion)
{
	t_flags	flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	while (is_flag_character(*(++ptr)))
		set_flags(*ptr, &flags);
	flags.width = ft_atoi(ptr);
	while ('0' <= *ptr && *ptr <= '9')
		ptr++;
	if (*ptr == '.')
	{
		flags.precision = ft_atoi(++ptr);
		flags.zero_padding = F_ZERO_PRECISION;
	}
	if (conversion == 'd' || conversion == 'i')
		return (print_dec(num, &flags));
	if (conversion == 'x' || conversion == 'X')
		return (print_hex(num, &flags, conversion));
	if (conversion == 'u')
		return (print_uint((unsigned int)num, &flags));
	return (0);
}
