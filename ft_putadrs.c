/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichinoseyuuki <ichinoseyuuki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:41:17 by yichinos          #+#    #+#             */
/*   Updated: 2022/10/31 21:22:45 by ichinoseyuu      ###   ########.fr       */
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
	count += ft_putnbr_small_sixteen(a);
	return (count);
}
