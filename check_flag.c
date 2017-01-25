/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:38:32 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/25 09:40:33 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag_1(t_struc *struc, const char *str, int z, int y)
{
	if (str[y] == '#')
	{
		struc->flag.diese = 1;
		return (1);
	}
	if (str[y] == '0')
	{
		struc->flag.zero = 1;
		return (1);
	}
	return (0);
}

int			check_flag(t_struc *struc, const char *str, int z, int y)
{
	while (y < z)
	{
		if (str[y] == '-')
		{
			struc->flag.tiret = 1;
			return (1);
		}
		if (str[y] == '+')
		{
			struc->flag.plus = 1;
			return (1);
		}
		if (str[y] == ' ')
		{
			struc->flag.espace = 1;
			return (1);
		}
		if ((check_flag_1(struc, str, z, y)) != 0)
			return (1);
		y++;
	}
	return (0);
}
