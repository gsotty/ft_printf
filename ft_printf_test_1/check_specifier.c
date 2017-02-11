/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:33:05 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/11 14:11:20 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_specifier_4(t_struc *struc, const char *str, int z)
{
	if (str[z] == 'x')
	{
		struc->specifier.x = 1;
		return (z);
	}
	else if (str[z] == 'X')
	{
		struc->specifier.xm = 1;
		return (z);
	}
	else if (str[z] == 'p')
	{
		struc->specifier.p = 1;
		return (z);
	}
	else if (str[z] == '%')
	{
		struc->specifier.pourcent = 1;
		return (z);
	}
	else if (ft_verif_char(str[z]) == 0)
		return (-1);
	return (0);
}

static int	check_specifier_3(t_struc *struc, const char *str, int z)
{
	int		test;

	test = 0;
	if (str[z] == 'U')
	{
		struc->specifier.um = 1;
		return (z);
	}
	else if (str[z] == 'O')
	{
		struc->specifier.om = 1;
		return (z);
	}
	else if ((test = check_specifier_4(struc, str, z)) == -1)
		return (-1);
	else if (test != 0)
		return (z);
	return (0);
}

static int	check_specifier_2(t_struc *struc, const char *str, int z)
{
	int		test;

	test = 0;
	if (str[z] == 's')
	{
		struc->specifier.s = 1;
		return (z);
	}
	else if (str[z] == 'S')
	{
		struc->specifier.sm = 1;
		return (z);
	}
	else if (str[z] == 'u')
	{
		struc->specifier.u = 1;
		return (z);
	}
	else if ((test = check_specifier_3(struc, str, z)) == -1)
		return (-1);
	else if (test != 0)
		return (z);
	return (0);
}

static int	check_specifier_1(t_struc *struc, const char *str, int z)
{
	int		test;

	test = 0;
	if (str[z] == 'D')
	{
		struc->specifier.dm = 1;
		return (z);
	}
	else if (str[z] == 'i')
	{
		struc->specifier.i = 1;
		return (z);
	}
	else if (str[z] == 'o')
	{
		struc->specifier.o = 1;
		return (z);
	}
	else if ((test = check_specifier_2(struc, str, z)) == -1)
		return (-1);
	else if (test != 0)
		return (z);
	return (0);
}

int			check_specifier(t_struc *struc, const char *str, int z, int test)
{
	while (str[z] != '\0')
	{
		if (str[z] == 'c')
		{
			struc->specifier.c = 1;
			return (z);
		}
		else if (str[z] == 'C')
		{
			struc->specifier.cm = 1;
			return (z);
		}
		else if (str[z] == 'd')
		{
			struc->specifier.d = 1;
			return (z);
		}
		else if ((test = check_specifier_1(struc, str, z)) == -1)
			return (z - 1);
		else if (test != 0)
			return (z);
		z++;
	}
	return (0);
}
