/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 09:58:01 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/21 16:39:51 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static size_t	ft_intlen_base(unsigned long n, int base)
{
	long	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

static char		ft_findchar(unsigned long value, int base)
{
	if (value % base < 10)
		return ('0' + (value % base));
	else
		return ('a' - 10 + (value % base));
}

char			*ft_unsigned_long_itoa_base(unsigned long value, int base)
{
	unsigned long	size;
	unsigned long	i;
	char			*tmp;
	unsigned long	u_value;

	u_value = value;
	size = ft_intlen_base(u_value, base);
	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	tmp[size] = '\0';
	if (!u_value)
		tmp[0] = '0';
	i = size - 1;
	while (u_value)
	{
		tmp[i] = ft_findchar(u_value, base);
		u_value = u_value / base;
		i--;
	}
	return (tmp);
}
