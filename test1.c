/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:25:56 by yichinos          #+#    #+#             */
/*   Updated: 2022/10/28 17:41:46 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

typedef struct s_args
{
	int	c;
	int	width;
	int	has_width;
	int	precision;
	int	has_precision;
}	t_args;

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
		return ;
	count = 0;
	while (*s != '\0')
	{
		count += ft_putchar(*s);
		s++;
	}
	ft_putchar('\0');
	return (count);
}

int	ft_vfprintf(const char *format, va_list ap, int done) // put_straeg;
{
	int		num;
	char	*s2;
	char	centens;

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
		else if (*(format + 1) == '%')
		{
			format++;
			ft_putchar('%');
		}
		format++;
		return (done);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	char	*string;

	count = 0;
	string = *format;
	va_start(ap, format);
	read_string;
	put_strarg;
	va_end(ap);
	return (count);
}

int	main(void)
{
	ft_printf("abcde%c\n", 'F');
	ft_printf("abcde%c\n", 'W');
	ft_printf("a%cc%ce%%\n", 'B', 'D', 'a');
	printf("---------ft_printf---------\n");
	ft_printf("aiueo: %s\n12345: %d\nA : %c\n %%\n", "aiueo", 12345, 'A');
	printf("----------printf-----------\n");
	printf("aiueo: %s\n12345: %d\nA : %c\n %%\n", "aiueo", 12345, 'A');
	return (0);
}
