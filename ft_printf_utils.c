/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:05:08 by eshintan          #+#    #+#             */
/*   Updated: 2024/01/30 09:07:16 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigned(unsigned int num)
{
	int	len;

	len = 0;
	if (num >= 10)
		len += put_unsigned(num / 10);
	len += put_char(num % 10 + '0');
	return (len);
}

int	put_hex(unsigned long num, int uppercase)
{
	char	*hex_digits;
	int		len;

	len = 0;
	hex_digits = "0123456789abcdef";
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		len += put_hex(num / 16, uppercase);
	len += put_char(hex_digits[num % 16]);
	return (len);
}

int	put_ptr(void *ptr)
{
	long	len;

	len = 0;
	len += put_str("0x");
	len += put_hex((unsigned long)ptr, 0);
	return (len);
}

int	put_percent(void)
{
	write(1, "%", 1);
	return (1);
}
