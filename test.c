/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:48:59 by yichinos          #+#    #+#             */
/*   Updated: 2022/10/28 15:02:15 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	print_num(int *fmt, ...)
{
	va_list	ap;
	int		num;

	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'd')
			{
				num = (int)va_arg(ap, int);
				ft_putnbr(num, 1);
			}
		}
		fmt++;
	}
	va_end(ap);
}


void	print_string(char *s, ...)
{
	va_list	ap;
	char	*s1;

	va_start(ap, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			if (*s == 's')
			{
				s1 = (char *)va_arg(ap, char *);
				ft_putstr(s1, 1);
			}
			s++;
		}
		ft_putchar(*s, 1);
		s++;
	}
	va_end(ap);
}

void	print_c(char *c, ...)
{
	va_list	ap;
	char	s;

	va_start(ap, c);
	while (*c != '\0')
	{
		if (*c == '%')
		{
			c++;
			if (*c == 'c')
			{
				s = va_arg(ap, int);
				write(1, &s, 1);
			}
			c++;
		}
		ft_putchar(*c, 1);
		c++;
	}
	va_end(ap);
}

int	check_conv(const char c)
{
	if (c == 'c')
		putchar()
	else if (c == 'd')
		putnum
	else if (c == 'p')
		putadress
	else if (c == 's')
		putstring
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		number;

	va_start(ap, format);
	number =
	va_end(ap);
	return (number);
}


