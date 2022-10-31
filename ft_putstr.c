/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:30:23 by yichinos          #+#    #+#             */
/*   Updated: 2022/10/31 14:56:41 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		ft_putstr("(NULL)");
	count = 0;
	while (*s || s)
	{
		count += ft_putchar(*s);
		s++;
	}
	return (count);
}
