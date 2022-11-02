/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:23:17 by yichinos          #+#    #+#             */
/*   Updated: 2022/11/02 12:06:06 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int	ft_vfprintf(const char *format, va_list ap)
{
	int	count;

	count = 0;
	if (*format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (*format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (*format == 'x')
		count += ft_putnbr_small_sixteen(va_arg(ap, unsigned int));
	else if (*format == 'X')
		count += ft_putnbr_big_sixteen(va_arg(ap, unsigned int));
	else if (*format == 'p')
		count += ft_putadrs(va_arg(ap, uintptr_t));
	else if (*format == 'u')
		count += ft_put_u_nbr(va_arg(ap, unsigned int));
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			count += ft_putchar(*format);
		else
		{
			format++;
			count += ft_vfprintf(format, ap);
		}
		format++;
	}
	va_end(ap);
	return (count);
}
