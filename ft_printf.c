/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:23:17 by yichinos          #+#    #+#             */
/*   Updated: 2022/11/01 15:08:39 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int	ft_vfprintf(const char *format, va_list ap, int *done)
{
	if (*format == 's')
		done += ft_putstr(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		done += ft_putnbr(va_arg(ap, int));
	else if (*format == 'c')
		done += ft_putchar(va_arg(ap, int));
	else if (*format == 'x')
		done += ft_putnbr_small_sixteen(va_arg(ap, unsigned int));
	else if (*format == 'X')
		done += ft_putnbr_big_sixteen(va_arg(ap, unsigned int));
	else if (*format == 'p')
		done += ft_putadrs(va_arg(ap, uintptr_t));
	else if (*format == 'u')
		done += ft_put_u_nbr(va_arg(ap, unsigned int));
	else if (*format == '%')
		done += ft_putchar('%');
	return (*done);
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
			count += ft_vfprintf(format, ap, &count);
		}
		format++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int	i;
	int	j;
	char	*c;

	c = malloc(sizeof(int) * (INT_MAX));

	printf("---------ft_printf---------\n");

	i = ft_printf("%c,%s,%p,%d,%i,%u,%x,%X,%%\n",'\0',"",&i,0,INT_MIN,INT_MAX,INT_MIN,UINT_MAX);
	printf("%d\n", i);
	// ft_printf("%s\n", s1);
	// ft_printf("%s\n", s1);
	// ft_printf("%s\n", s1);
	// ft_printf("%s\n", s1);
	printf("----------printf-----------\n");
	j = printf("%c,%s,%p,%d,%i,%u,%x,%X,%%\n",'\0',"",&i,0,INT_MIN,INT_MAX,INT_MIN,UINT_MAX);
	printf("%d\n", j);
	// printf("%s\n", s1);
	// printf("%s\n", s1);
	// printf("%s\n", s1);
	// printf("%s\n", s1);
	return (0);
}
