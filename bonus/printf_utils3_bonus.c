/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:38:06 by bena              #+#    #+#             */
/*   Updated: 2023/02/22 13:07:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	digit_of_address(unsigned long long num)
{
	unsigned long long	dummy;
	size_t				digit;

	dummy = 16;
	digit = 1;
	while (dummy - 1 < num)
	{
		dummy *= 16;
		digit++;
	}
	return (digit);
}
