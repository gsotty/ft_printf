/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:58:58 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/20 11:16:23 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_signe(unsigned int *n, int *signe)
{
	if (*n == 0)
	{
		*n *= -1;
		*signe = 1;
	}
}

char		*ft_unsigned_itoa(unsigned int n)
{
	unsigned int	nbr;
	int				i;
	int				signe;
	char			*tab;

	i = 2;
	nbr = n;
	signe = 0;
	ft_signe(&n, &signe);
	while (nbr /= 10)
		i++;
	i += signe;
	if ((tab = (char *)malloc(sizeof(char) * i)) == NULL)
		return (NULL);
	tab[--i] = '\0';
	while (i--)
	{
		tab[i] = ((n % 10) + '0');
		n = n / 10;
	}
	if (signe)
		tab[0] = '-';
	return (tab);
}
