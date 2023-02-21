/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:41:31 by bena              #+#    #+#             */
/*   Updated: 2023/02/22 03:33:36 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

static int	flush_buffer(char *buffer, char **ptr_buf);
static int	print_conversion(const char **ptr, va_list *ap);
int			print_int(int num, const char *ptr, char conversion);
int			print_uint(unsigned int num, const char *ptr);
int			print_char(char c, const char *ptr);
int			print_str(char *str, const char *ptr);
int			print_ptr(void *address, const char *ptr);
int			is_passable_character(const char c);

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		buffer[4096];
	const char	*ptr;
	char		*ptr_buf;
	int			output;

	va_start(ap, format);
	ptr_buf = buffer;
	ptr = format;
	output = 0;
	while (*ptr)
	{
		if (*ptr == '\n' || *ptr == '%' || ptr_buf - buffer == 4095)
			output += flush_buffer(buffer, &ptr_buf);
		if (*ptr == '%')
			output += print_conversion(&ptr, &ap);
		if (*ptr)
			*ptr_buf++ = *ptr++;
	}
	va_end(ap);
	output += flush_buffer(buffer, &ptr_buf);
	return (output);
}

static int	flush_buffer(char *buffer, char **ptr_buf)
{
	int	output;

	if (buffer >= *ptr_buf)
		return (0);
	write(1, buffer, *ptr_buf - buffer);
	output = *ptr_buf - buffer;
	*ptr_buf = buffer;
	return (output);
}

static int	print_conversion(const char **ptr, va_list *ap)
{
	const char	*c;
	int			conversion_length;

	c = *ptr;
	while (is_passable_character(*(++c)))
		;
	conversion_length = 1;
	if (*c == 'i' || *c == 'd' || *c == 'x' || *c == 'X' || *c == 'u')
		conversion_length = print_int(va_arg(*ap, int), *ptr, *c);
	if (*c == 'c')
		conversion_length = print_char(va_arg(*ap, int), *ptr);
	if (*c == 's')
		conversion_length = print_str(va_arg(*ap, char *), *ptr);
	if (*c == 'p')
		conversion_length = print_ptr(va_arg(*ap, void *), *ptr);
	if (*c == '%')
		write (1, c, 1);
	*ptr = c + 1;
	return (conversion_length);
}
