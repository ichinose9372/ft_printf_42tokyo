/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:41:17 by yichinos          #+#    #+#             */
/*   Updated: 2022/11/01 14:35:32 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putadrs(uintptr_t a)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (a == 0)
		count += write(1, 0, 1);
	count += ft_putnbr_small_sixteen((unsigned long int)a);
	return (count);
}
