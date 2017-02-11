/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_longeur_d_amd_i.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:18:48 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/11 10:37:37 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*modif_longeur_dm(t_struc *struc, va_list ap)
{
	intmax_t	tmp;

	if (struc->lenght.l == 1)
	{
		tmp = va_arg(ap, long long);
		if (tmp < 0)
		{
			struc->flag.negatif = 1;
			tmp = -tmp;
		}
		return (ft_intmax_t_itoa_base((long long)tmp, 10));
	}
	else
	{
		tmp = va_arg(ap, long);
		if (tmp < 0)
		{
			struc->flag.negatif = 1;
			tmp = -tmp;
		}
		return (ft_unsigned_long_itoa_base(tmp, 10));
	}
}
