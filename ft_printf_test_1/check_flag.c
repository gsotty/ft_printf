/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:38:32 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/27 13:20:26 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isnum_o(int c)
{
	if (('0' < c && c <= '9'))
		return (1);
	return (0);
}

static int	check_flag_1(t_struc *struc, const char *str, int y)
{
	if (str[y] == '#')
		struc->flag.diese = 1;
	if (str[y] == '0')
		struc->flag.zero = 1;
	return (1);
}

int			check_flag(t_struc *struc, const char *str, int z, int y)
{
	while (y < z && ft_isnum_o(str[y]) == 0)
	{
		if (str[y] == '-')
			struc->flag.tiret = 1;
		if (str[y] == '+')
			struc->flag.plus = 1;
		if (str[y] == ' ')
			struc->flag.espace = 1;
		check_flag_1(struc, str, y);
		y++;
	}
	return (0);
}
