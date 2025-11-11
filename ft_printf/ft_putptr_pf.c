/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:36:24 by abroslav          #+#    #+#             */
/*   Updated: 2025/05/21 23:43:26 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	unsigned long long	address;
	char				*hex_str;

	if (ptr == NULL)
	{
		ft_putstr_pf("(nil)", counter);
		return ;
	}
	address = (unsigned long long)ptr;
	hex_str = ft_aux_pf(address, "0123456789abcdef");
	if (hex_str == NULL)
		return ;
	ft_putstr_pf("0x", counter);
	ft_putstr_pf(hex_str, counter);
	free(hex_str);
}
