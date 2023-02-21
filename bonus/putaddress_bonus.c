/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putaddress_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:04:46 by bena              #+#    #+#             */
/*   Updated: 2023/02/22 03:32:18 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_nbr(char *buffer, size_t buffer_len);

void	put_address(unsigned long long num)
{
	char		buffer[16];
	char		*ptr;
	const char	*hex = "0123456789abcdef";

	ptr = buffer;
	if (num == 0)
		*ptr++ = '0';
	while (num)
	{
		*ptr++ = hex[num % 16];
		num /= 16;
	}
	write_nbr(buffer, ptr - buffer);
}

static void	write_nbr(char *buffer, size_t buffer_len)
{
	char	str[16];
	char	*ptr;

	ptr = str;
	buffer += buffer_len;
	while (buffer_len--)
		*ptr++ = *--buffer;
	write(1, str, ptr - str);
}
