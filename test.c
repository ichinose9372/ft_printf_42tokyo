/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:48:59 by yichinos          #+#    #+#             */
/*   Updated: 2022/10/27 16:51:47 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<limits.h>

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	while (*s != '\0')
	{
		ft_putchar(*s, fd);
		s++;
	}
}

void	ft_putnbr(int n, int fd)
{
	if (n == INT_MIN)
	{
		ft_putchar('-', fd);
		ft_putchar('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
	else
		ft_putchar(n + '0', fd);
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
	if (format == NULL)
		number = -1;
	while (0 >= number && *format)
	{

		if (*format != '%')
			write(1, format, 1);
		else
			
			check(*(format + 1));
		format++;
	}
	va_end(ap);
	return (number);
}


int	main(void)
{
	ft_printf("\0");
	return (0);
}
