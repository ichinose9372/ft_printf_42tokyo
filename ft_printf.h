/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:28:47 by yichinos          #+#    #+#             */
/*   Updated: 2022/11/02 15:46:00 by yichinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>

int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_put_u_nbr(unsigned int n);
int	ft_putnbr_big_sixteen(unsigned int long x);
int	ft_putnbr_small_sixteen(unsigned int long x);
int	ft_putadrs(uintptr_t point);
int	ft_vfprintf(const char *format, va_list ap);
int	ft_printf(const char *format, ...);

#endif
