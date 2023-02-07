/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 02:19:17 by bena              #+#    #+#             */
/*   Updated: 2023/02/13 06:17:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"

void		*ft_memset(void *b, int c, size_t len);
int			ft_atoi(const char *str);
void		set_flags(const char c, t_flags *flags);
int			is_flag_character(const char c);
static void	put_result(char *s, t_flags *flags, size_t width, size_t precision);
size_t		ft_strlen(const char *s);
size_t		min_len(size_t a, size_t b);
void		ft_putstrn(char *s, size_t buffer);

int	print_str(char *str, const char *ptr)
{
	t_flags	flags;
	size_t	width;
	size_t	precision;

	ft_memset(&flags, 0, sizeof(t_flags));
	precision = -1;
	while (is_flag_character(*(++ptr)))
		set_flags(*ptr, &flags);
	width = ft_atoi(ptr);
	while ('0' <= *ptr && *ptr <= '9')
		ptr++;
	if (*ptr == '.')
		precision = ft_atoi(++ptr);
	put_result(c, &flags, width, precision);
}

static void	put_result(char *s, t_flags *flags, size_t width, size_t precision)
{
	size_t	space_length;

	precision = min_len(ft_strlen(s), precision);
	space_length = width - precision;
	if (flags->left_align == 1)
		while (width-- > 0)
			write(1, " ", 1);
	ft_putstrn(s, precision);
	if (flags->left_align == 0)
		while (width-- > 0)
			write(1, " ", 1);
}
