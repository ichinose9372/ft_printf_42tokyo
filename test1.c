/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:25:56 by yichinos          #+#    #+#             */
/*   Updated: 2022/10/30 15:45:04 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (*s != '\0')
	{
		count += ft_putchar(*s);
		s++;
	}
	ft_putchar('\0');
	return (count);
}

int	ft_putnbr_big_sixteen(int unsigned x)
{
	unsigned int	r;
	int				count;

	count = 0;
	r = x % 16;
	x = x / 16;
	if (x > 0)
		ft_putnbr_big_sixteen(x);
	if (r >= 0 && r <= 9)
		count += ft_putchar((char)r + '0');
	else if (r > 9)
		count += ft_putchar('A' +(char)r - 10);
	return (count);
}

int	ft_putnbr_small_sixteen(unsigned int x)
{
	unsigned int	r;
	int				count;

	count = 0;
	r = x % 16;
	x = x / 16;
	if (x > 0)
		ft_putnbr_small_sixteen(x);
	if (r >= 0 && r <= 9)
		ft_putchar((char)r + '0');
	else if (r > 9)
		ft_putchar('a' +(char)r - 10);
	return (count);
}

int	ft_putadres(unsigned int	a)
{
	int				count;
	unsigned int	adres;

	count = 0;
	adres = (unsigned int)&a;
	count += write(1, "0x", 2);
	count += ft_putnbr_small_sixteen(adres);
	return (count);
}

int	ft_vfprintf(const char *format, va_list ap, int done) // put_straeg;
{
	int				num;
	char			*s2;
	char			centens;
	unsigned int	num2;

	while (*format != '\0')
	{
		if (*format != '%')
			ft_putchar(*format);
		else if (*(format + 1) == 's')
		{
			format++;
			s2 = (char *)va_arg(ap, char *);
			ft_putstr(s2);
		}
		else if (*(format + 1) == 'd')
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
		else if (*(format + 1) == 'x' || *(format + 1) == 'x')
		{
			format++;
			if (*format == 'x')
			{
				num2 = (unsigned int)va_arg(ap, unsigned int);
				ft_putnbr_small_sixteen(num2);
			}
			else
			{
				num2 = (int)va_arg(ap, unsigned int);
				ft_putnbr_big_sixteen(num2);
			}
		}
		else if (*(format + 1) == '%')
		{
			format++;
			ft_putchar('%');
		}
		else if (*(format + 1) == 'p')
		{
			format++;
			num2 = va_arg(ap, unsigned int);
			ft_putadres(num2);
		}
		format++;
	}
	return (done);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	char	*string;

	count = 0;
	va_start(ap, format);
	ft_vfprintf(format, ap, count);
	va_end(ap);
	return (count);
}

int	main(void)
{
	int	i;
	int	*p;
	p = &i;
	char	*q;
	// ft_printf("abcde%p\n", i);
	// ft_printf("abcde%c\n", 'W');
	// ft_printf("a%cc%ce%%\n", 'B', 'D', 'a');
	printf("---------ft_printf---------\n");
	ft_printf("%p\n", p);
	printf("----------printf-----------\n");
	printf("%p\n", p);
	return (0);
}
