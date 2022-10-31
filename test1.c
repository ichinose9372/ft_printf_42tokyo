/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:25:56 by yichinos          #+#    #+#             */
/*   Updated: 2022/10/31 14:08:57 by yichinos         ###   ########.fr       */
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
		return (write(1, "(null)", 6));
	count = 0;
	while (*s || s)
	{
		count += ft_putchar(*s);
		s++;
	}
	return (count);
}

int	ft_putnbr_big_sixteen(uintptr_t x)
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

int	ft_putnbr_small_sixteen(uintptr_t x)
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

int	ft_putadres(uintptr_t a)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_putnbr_small_sixteen(a);
	return (count);
}

int	ft_put_u_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 0)
		ft_put_u_nbr(UINT_MAX);
	if (n >= 10)
	{
		ft_put_u_nbr(n / 10);
		ft_put_u_nbr(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

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
			s2 = (char *)va_arg(ap, char *);
			ft_putstr(s2);
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
			ft_putadres(j);
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
	char	*string;

	count = 0;
	va_start(ap, format);
	ft_vfprintf(format, ap, count);
	va_end(ap);
	return (count);
}

int	main(void)
{
	// char	s1[5] = {"abcde"};

	ft_put_u_nbr(-21);
	printf("\n");
	ft_put_u_nbr(0);
	printf("\n");
	ft_put_u_nbr(21);
	printf("\n");
	printf("%u\n", -21);
	printf("%u\n", 4294967295);
	// printf("---------ft_printf---------\n");
	// ft_printf("%p\n", &s1[0]);
	// ft_printf("%p\n", &s1[1]);
	// ft_printf("%p\n", &s1[2]);
	// ft_printf("%p\n", &s1[3]);
	// ft_printf("%p\n", &s1[4]);
	// printf("----------printf-----------\n");
	// printf("%p\n", &s1[0]);
	// printf("%p\n", &s1[1]);
	// printf("%p\n", &s1[2]);
	// printf("%p\n", &s1[3]);
	// printf("%p\n", &s1[4]);
	return (0);
}
