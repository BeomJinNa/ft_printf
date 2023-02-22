/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 02:19:17 by bena              #+#    #+#             */
/*   Updated: 2023/02/22 12:16:06 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"

void		*ft_memset(void *b, int c, size_t len);
int			ft_atoi(const char *str);
void		set_flags(const char c, t_flags *flags);
int			is_flag_character(const char c);
static int	put_result(char *s, t_flags *flags);
size_t		ft_strlen(const char *s);
size_t		min_len(size_t a, size_t b);
void		ft_putstrn(char *s, size_t buffer);

int	print_str(char *str, const char *ptr)
{
	t_flags		flags;
	char *const	null_string = "(null)";

	if (str == NULL)
		str = null_string;
	ft_memset(&flags, 0, sizeof(t_flags));
	flags.precision = -1;
	while (is_flag_character(*(++ptr)))
		set_flags(*ptr, &flags);
	flags.width = ft_atoi(ptr);
	while ('0' <= *ptr && *ptr <= '9')
		ptr++;
	if (*ptr == '.')
		flags.precision = ft_atoi(++ptr);
	return (put_result(str, &flags));
}

static int	put_result(char *s, t_flags *flags)
{
	size_t	space_length;
	int		output;

	flags->precision = min_len(ft_strlen(s), flags->precision);
	space_length = flags->width - flags->precision;
	if (flags->width < flags->precision)
		space_length = 0;
	output = space_length + flags->precision;
	if (flags->left_align == 0)
		while (space_length-- > 0)
			write(1, " ", 1);
	ft_putstrn(s, flags->precision);
	if (flags->left_align == 1)
		while (space_length-- > 0)
			write(1, " ", 1);
	return (output);
}