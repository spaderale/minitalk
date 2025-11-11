/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upp_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:50:02 by abroslav          #+#    #+#             */
/*   Updated: 2025/05/20 22:53:11 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_upp_pf(unsigned int num, size_t *counter)
{
	char	*str;

	str = ft_aux_pf((unsigned long long)num, "0123456789ABCDEF");
	if (!str)
		return ;
	ft_putstr_pf(str, counter);
	free(str);
}
