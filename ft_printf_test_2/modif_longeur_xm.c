/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_longeur_xm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:56:01 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/10 16:02:56 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*modif_longeur_2(t_struc *struc, va_list ap)
{
	uintmax_t	tmp;

	if (struc->lenght.z == 1)
	{
		tmp = (size_t)va_arg(ap, uintmax_t);
		if (tmp == 0)
			struc->flag.negatif = 1;
		return (ft_unsigned_long_itoa_base_m(tmp, 16));
	}
	else
	{
		tmp = va_arg(ap, unsigned int);
		if (tmp == 0)
			struc->flag.negatif = 1;
		return (ft_unsigned_itoa_base_m(tmp, 16));
	}
}

static char	*modif_longeur_1(t_struc *struc, va_list ap)
{
	uintmax_t	tmp;

	if (struc->lenght.l == 1)
	{
		tmp = (long)va_arg(ap, intmax_t);
		if (tmp == 0)
			struc->flag.negatif = 1;
		return (ft_unsigned_long_itoa_base_m(tmp, 16));
	}
	else if (struc->lenght.ll == 1)
	{
		tmp = (long long)va_arg(ap, intmax_t);
		if (tmp == 0)
			struc->flag.negatif = 1;
		return (ft_uintmax_t_itoa_base_m(tmp, 16));
	}
	else if (struc->lenght.j == 1)
	{
		tmp = va_arg(ap, uintmax_t);
		if (tmp == 0)
			struc->flag.negatif = 1;
		return (ft_uintmax_t_itoa_base_m(tmp, 16));
	}
	return (modif_longeur_2(struc, ap));
}

char		*modif_longeur_xm(t_struc *struc, va_list ap)
{
	uintmax_t	tmp;

	if (struc->lenght.h == 1)
	{
		tmp = (unsigned short)va_arg(ap, int);
		if (tmp == 0)
			struc->flag.negatif = 1;
		return (ft_itoa_base_m(tmp, 16));
	}
	else if (struc->lenght.hh == 1)
	{
		tmp = (unsigned char)va_arg(ap, int);
		if (tmp == 0)
			struc->flag.negatif = 1;
		return (ft_itoa_base_m(tmp, 16));
	}
	return (modif_longeur_1(struc, ap));
}
