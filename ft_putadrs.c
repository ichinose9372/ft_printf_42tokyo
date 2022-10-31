/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:41:17 by yichinos          #+#    #+#             */
/*   Updated: 2022/10/31 14:41:49 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putadres(uintptr_t a)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_putnbr_small_sixteen(a);
	return (count);
}
