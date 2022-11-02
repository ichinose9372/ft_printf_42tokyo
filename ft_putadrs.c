/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:41:17 by yichinos          #+#    #+#             */
/*   Updated: 2022/11/02 15:47:27 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

int	ft_putadrs(uintptr_t point)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (!point)
		count += write(1, "0", 1);
	else
		count += ft_putnbr_small_sixteen((unsigned long int)point);
	return (count);
}
