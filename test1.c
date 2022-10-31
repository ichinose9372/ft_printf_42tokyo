/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:25:56 by yichinos          #+#    #+#             */
/*   Updated: 2022/10/31 16:07:01 by yichinos         ###   ########.fr       */
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

	if (s ==  NULL)
		ft_putstr("(NULL)");
	count = 0;
	while (*s && s)
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

int	ft_putadrs(uintptr_t a)
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
	char	*string;

	count = 0;
	va_start(ap, format);
	ft_vfprintf(format, ap, count);
	va_end(ap);
	return (count);
}

int	main(void)
{
	char	s1[5] = {"abcde"};


	printf("---------ft_printf---------\n");
	ft_printf("abcdef%s\n", s1);
	// ft_printf("%s\n", s1);
	// ft_printf("%s\n", s1);
	// ft_printf("%s\n", s1);
	// ft_printf("%s\n", s1);
	printf("----------printf-----------\n");
	printf("%s\n", s1);
	printf("%s\n", s1);
	printf("%s\n", s1);
	printf("%s\n", s1);
	printf("%s\n", s1);
	return (0);
}
