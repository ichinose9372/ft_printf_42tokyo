/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:35:06 by yichinos          #+#    #+#             */
/*   Updated: 2022/11/01 15:17:52 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
		count += 2;
	}
	if (n < 0)
	{
		ft_putchar('-');
		count++;
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		count++;
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
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

int main(void)
{
	int i;
	int j;
	i = 1123;
	j = ft_putnbr(i);
	ft_putchar('\n');
	ft_putnbr(j);
	return (0);
}
