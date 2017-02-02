/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:04:42 by tapperce          #+#    #+#             */
/*   Updated: 2016/11/28 11:04:47 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	nb_len(int n)
{
	int		len;

	len = 1;
	if (n < 0)
		len++;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str_nb;

	len = nb_len(n);
	str_nb = ft_strnew(len);
	if (!str_nb)
		return (NULL);
	if (n < 0)
		str_nb[0] = '-';
	while (len > 0 && str_nb[len - 1] != '-')
	{
		if (n < 0)
			str_nb[--len] = -(n % 10) + '0';
		else
			str_nb[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str_nb);
}
