/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:43:14 by eshintan          #+#    #+#             */
/*   Updated: 2024/01/30 09:02:03 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include"limits.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			put_char(format[i++]);
			count++;
		}
		else
		{
			count += sort_format(args, format[i + 1]);
			i += 2;
		}
	}
	va_end(args);
	return (count);
}

int	sort_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		return (put_char(va_arg(args, int)));
	else if (format == 's')
		return (put_str(va_arg(args, char *)));
	else if (format == 'p')
		return (put_ptr(va_arg(args, void *)));
	else if (format == 'i' || format == 'd')
		return (put_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (put_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (put_hex(va_arg(args, unsigned int), (format == 'X')));
	else if (format == '%')
		return (put_percent());
	return (0);
}

int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		put_str("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	put_nbr(int num)
{
	int	len;

	len = 0;
	if (num == INT_MIN)
	{
		put_str("-2147483648");
		return (11);
	}
	if (num < 0)
	{
		put_char('-');
		num = -num;
		len++;
	}
	if (num >= 10)
	{
		len += put_nbr(num / 10);
	}
	len += put_char(num % 10 + '0');
	return (len);
}

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
