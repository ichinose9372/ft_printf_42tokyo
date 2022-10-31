/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:23:17 by yichinos          #+#    #+#             */
/*   Updated: 2022/10/31 16:08:53 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_vfprintf(const char *format, va_list ap, int done)
{
	while (*format != '\0')
	{
		if (*format != '%')
			ft_putchar(*format);
		else
		{
			format++;
			if (*format == 's')
				done += ft_putstr(va_arg(ap, char *));
			else if (*format == 'd' || *format == 'i')
				ft_putnbr(va_arg(ap, int));
			else if (*format == 'c')
				ft_putchar(va_arg(ap, int));
			else if (*format == 'x')
				ft_putnbr_small_sixteen(va_arg(ap, uintptr_t));
			else if (*format == 'X')
				ft_putnbr_big_sixteen(va_arg(ap, uintptr_t));
			else if (*format == 'p')
				ft_putadrs(va_arg(ap, uintptr_t));
			else if (*format == 'u')
				ft_put_u_nbr(va_arg(ap, unsigned int));
			else if (*format == '%')
				ft_putchar('%');
		}
		format++;
	}
	return (done);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	ft_vfprintf(format, ap, count);
	va_end(ap);
	return (count);
}
