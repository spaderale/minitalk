/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:53:49 by abroslav          #+#    #+#             */
/*   Updated: 2025/05/22 20:44:40 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);

void	ft_putchar_pf(int c, size_t *counter);
void	ft_putstr_pf(char *str, size_t *counter);
void	ft_putnbr_pf(int num, size_t *counter);
void	ft_putuint_pf(unsigned int num, size_t *counter);
void	ft_puthex_low_pf(unsigned int num, size_t *counter);
void	ft_puthex_upp_pf(unsigned int num, size_t *counter);
void	ft_putptr_pf(void *ptr, size_t *counter);
char	*ft_aux_pf(unsigned long long n, char *base);

#endif
