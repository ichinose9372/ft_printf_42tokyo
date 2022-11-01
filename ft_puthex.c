/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:39:29 by yichinos          #+#    #+#             */
/*   Updated: 2022/11/01 18:04:04 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

int	ft_putnbr_big_sixteen(unsigned long int x)
{
	unsigned int	r;
	int				count;

	count = 0;
	r = x % 16;
	x = x / 16;
	if (x > 0)
		count += ft_putnbr_big_sixteen(x);
	if (r >= 0 && r <= 9)
		count += ft_putchar((char)r + '0');
	else if (r > 9)
		count += ft_putchar('A' +(char)r - 10);
	return (count);
}

int	ft_putnbr_small_sixteen(unsigned long int x)
{
	unsigned int	r;
	int				count;

	count = 0;
	r = x % 16;
	x = x / 16;
	if (x > 0)
		count += ft_putnbr_small_sixteen(x);
	if (r >= 0 && r <= 9)
		count += ft_putchar((char)r + '0');
	else if (r > 9)
		count += ft_putchar('a' +(char)r - 10);
	return (count);
}
