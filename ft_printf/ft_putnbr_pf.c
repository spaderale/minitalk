/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:34:25 by abroslav          #+#    #+#             */
/*   Updated: 2025/05/21 17:55:27 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int num, size_t *counter)
{
	if (num == -2147483648)
	{
		ft_putstr_pf("-2147483648", counter);
		return ;
	}
	if (num < 0)
	{
		ft_putchar_pf('-', counter);
		num = -num;
	}
	if (num > 9)
		ft_putnbr_pf(num / 10, counter);
	ft_putchar_pf((num % 10 + '0'), counter);
}
