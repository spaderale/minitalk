/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:49:55 by abroslav          #+#    #+#             */
/*   Updated: 2025/05/22 20:27:10 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list args, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(args, int), counter);
	else if (*str == 's')
		ft_putstr_pf(va_arg(args, char *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr_pf(va_arg(args, int), counter);
	else if (*str == 'u')
		ft_putuint_pf(va_arg(args, unsigned int), counter);
	else if (*str == 'x')
		ft_puthex_low_pf(va_arg(args, unsigned int), counter);
	else if (*str == 'X')
		ft_puthex_upp_pf(va_arg(args, unsigned int), counter);
	else if (*str == 'p')
		ft_putptr_pf(va_arg(args, void *), counter);
	else if (*str == '%')
		ft_putchar_pf('%', counter);
	else
	{
		ft_putchar_pf('%', counter);
		ft_putchar_pf(*str, counter);
	}
}

int	ft_printf(char const *str, ...)
{
	va_list		args;
	size_t		counter;

	if (!str)
		return (-1);
	counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(args, (char *)str, &counter);
		}
		else
			ft_putchar_pf(*str, &counter);
		str++;
	}
	va_end(args);
	return (counter);
}
