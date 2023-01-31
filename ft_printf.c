/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:41:31 by bena              #+#    #+#             */
/*   Updated: 2023/01/31 10:21:55 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#define ERROR 0

static void	flush_buffer(char *buffer, char **ptr_buf);
const char	*print_conversion(const char *ptr, va_list *ap);
int			print_int(int num, char conversion);
int			print_char(char c);
int			print_str(char *str);
int			print_ptr(void *ptr);

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		buffer[4096];
	const char	*ptr;
	char		*ptr_buf;

	va_start(ap, format);
	ptr_buf = buffer;
	ptr = format;
	while (*ptr)
	{
		if (*ptr == '\n' || *ptr == '%' || ptr_buf - buffer == 4095)
			flush_buffer(buffer, &ptr_buf);
		if (*ptr == '%')
			ptr = print_conversion(ptr, &ap);
		if (ptr == ERROR)
			break ;
		if (*ptr)
			*ptr_buf++ = *ptr++;
	}
	va_end(ap);
	if (ptr == ERROR)
		return (-1);
	return (ptr - format);
}

static void	flush_buffer(char *buffer, char **ptr_buf)
{
	if (buffer >= *ptr_buf)
		return ;
	write(1, buffer, *ptr_buf - buffer);
	*ptr_buf = buffer;
}

const char	*print_conversion(const char *ptr, va_list *ap)
{
	int			error;
	const char	*c;

	c = ptr;
	error = 0;
	while (1)
	{
		c++;
		if (*c != 'c' && *c != 's' && *c != 'p' && *c != 'd' && *c != 'i'
			&& *c != 'u' && *c != 'x' && *c != 'X' && *c != '%')
			continue ;
		if (*c == 'd' || *c == 'i' || *c == 'u' || *c == 'x' || *c == 'X')
			error = print_int(va_arg(*ap, int), *c);
		if (*c == 'c')
			error = print_char(va_arg(*ap, int));
		if (*c == 's')
			error = print_str(va_arg(*ap, char *));
		if (*c == 'p')
			error = print_ptr(va_arg(*ap, void *));
		if (*c == '%')
			write (1, c, 1);
		if (error)
			return (ERROR);
		break ;
	}
	return (c + 1);
}
