/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:23:17 by yichinos          #+#    #+#             */
/*   Updated: 2022/10/31 14:51:04 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_vfprintf(const char *format, va_list ap, int done)
{
	int				num;
	char			*s2;
	char			centens;
	unsigned int	num2;
	uintptr_t		j;

	while (*format != '\0')
	{
		if (*format != '%')
			ft_putchar(*format);
		else if (*(format + 1) == 's')
		{
			format++;
			// s2 = (char *)va_arg(ap, char *);
			ft_putstr(va_arg(ap, char *));
		}
		else if (*(format + 1) == 'd' || *(format + 1) == 'i')
		{
			format++;
			num = (int)va_arg(ap, int);
			ft_putnbr(num);
		}
		else if (*(format + 1) == 'c')
		{
			format++;
			centens = (char)va_arg(ap, int);
			ft_putchar(centens);
		}
		else if (*(format + 1) == 'x' || *(format + 1) == 'X')
		{
			format++;
			if (*format == 'x')
			{
				j = va_arg(ap, uintptr_t);
				ft_putnbr_small_sixteen(num2);
			}
			else
			{
				j = va_arg(ap, uintptr_t);
				ft_putnbr_big_sixteen(num2);
			}
		}
		else if (*(format + 1) == 'p')
		{
			format++;
			j = va_arg(ap, uintptr_t);
			ft_putadrs(j);
		}
		else if (*(format + 1) == 'u')
		{
			format++;
			num2 = va_arg(ap, unsigned int);
			ft_put_u_nbr(num2);
		}
		else if (*(format + 1) == '%')
		{
			format++;
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
