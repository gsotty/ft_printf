/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:02:51 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/20 16:19:50 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_float(float nbr)
{
	int		test;
	int		x;
	float	tmp;
	char	*tab;

	x = 0;
	test = 1;
	tmp = nbr;
	tab = ft_memalloc(13);
	while (x < 8)
	{
		tab[x] = (int)tmp + '0';
		tmp = tmp - (int)tmp;
		if (tmp < 1 && test == 1)
		{
			x++;
			test = 0;
			tab[x] = '.';
		}
		tmp = tmp * 10;
		ft_putchar(tab[x]);
		ft_putstr("\n");
		x++;
	}
	return (tab);
}

int		main(void)
{
	float	x;

	x = 1.9999998;
	ft_putstr(ft_float(x));
	ft_putstr("\n");
	printf("%s\n", ft_itoa_base(*(int *)&x, 2));
	printf("%d\n", *(int *)&x);
	printf("%e\n", x);
	return (0);
}
