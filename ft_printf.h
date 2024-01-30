/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 06:12:58 by eshintan          #+#    #+#             */
/*   Updated: 2024/01/30 09:06:04 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	sort_format(va_list args, const char format);
int	put_char(char c);
int	put_str(char *str);
int	put_nbr(int num);
int	put_unsigned(unsigned int num);
int	put_hex(unsigned long num, int uppercase);
int	put_ptr(void *ptr);
int	put_percent(void);

#endif