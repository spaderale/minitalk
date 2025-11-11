/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:28:07 by abroslav          #+#    #+#             */
/*   Updated: 2025/05/25 01:52:30 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen_pf(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_bzero_pf(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

static void	*ft_calloc_pf(size_t nbr, size_t size)
{
	void	*dest;

	dest = malloc(nbr * size);
	if (dest == NULL)
		return (NULL);
	ft_bzero_pf(dest, nbr * size);
	return (dest);
}

static size_t	ft_len(unsigned long long n, char *base)
{
	size_t					len;
	unsigned long long		base_len;

	len = 1;
	base_len = ft_strlen_pf(base);
	while (n >= base_len)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}

char	*ft_aux_pf(unsigned long long n, char *base)
{
	char		*str;
	size_t		num_len;
	size_t		base_len;

	if (!base || ft_strlen_pf(base) < 2)
		return (NULL);
	num_len = ft_len(n, base);
	base_len = ft_strlen_pf(base);
	str = ft_calloc_pf((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len = num_len - 1;
		str[num_len] = base[n % base_len];
		n = n / base_len;
	}
	return (str);
}
