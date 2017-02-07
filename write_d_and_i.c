/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d_and_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:42:10 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/07 14:12:12 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*modif_longeur(t_struc *struc, va_list ap)
{
	intmax_t	tmp;

	if (struc->lenght.h == 1)
	{
		tmp = (short)va_arg(ap, int);
		if (tmp < 0)
		{
			struc->flag.negatif = 1;
			tmp = -tmp;
		}
		return (ft_itoa(tmp));
	}
	else if (struc->lenght.hh == 1)
	{
		tmp = (char)va_arg(ap, int);
		if (tmp < 0)
		{
			struc->flag.negatif = 1;
			tmp = -tmp;
		}
		return (ft_itoa(tmp));
	}
	else if (struc->lenght.l == 1)
	{
		tmp = va_arg(ap, long);
		if (tmp < 0)
		{
			struc->flag.negatif = 1;
			tmp = -tmp;
		}
		return (ft_long_itoa_base((long)tmp, 10));
	}
	else if (struc->lenght.ll == 1)
	{
		tmp = va_arg(ap, long long);
		if (tmp < 0)
		{
			struc->flag.negatif = 1;
			tmp = -tmp;
		}
		return (ft_intmax_t_itoa_base((long long)tmp, 10));
	}
	else if (struc->lenght.j == 1)
	{
		tmp = va_arg(ap, intmax_t);
		if (tmp < 0)
		{
			struc->flag.negatif = 1;
			tmp = -tmp;
		}
		return (ft_intmax_t_itoa_base((intmax_t)tmp, 10));
	}
	else if (struc->lenght.z == 1)
	{
		tmp = va_arg(ap, size_t);
		if (tmp < 0)
		{
			struc->flag.negatif = 1;
			tmp = -tmp;
		}
		return (ft_unsigned_itoa_base((size_t)tmp, 10));
	}
	else
	{
		tmp = va_arg(ap, int);
		if (tmp < 0)
		{
			struc->flag.negatif = 1;
			tmp = -tmp;
		}
		return (ft_itoa_int_min(tmp));
	}
}

static char	*ft_largeur(t_struc *struc, char *tmp)
{
	char	*tmp_spaces;

	if (!(tmp_spaces = (char *)malloc(sizeof(char) * struc->width.number)))
		return (0);
	if (struc->flag.zero && (struc->flag.tiret == 0) &&
			(struc->precision.number == -1))
		tmp_spaces = ft_memset(tmp_spaces, 48, struc->width.number -
				ft_strlen(tmp));
	else
		tmp_spaces = ft_memset(tmp_spaces, 32, struc->width.number -
				ft_strlen(tmp));
	tmp_spaces[struc->width.number - ft_strlen(tmp)] = '\0';
	if (struc->flag.tiret)
		tmp = ft_strjoin(tmp, tmp_spaces);
	else
		tmp = ft_strjoin(tmp_spaces, tmp);
	return (tmp);
}

static char	*ft_if_precision(t_struc *struc, char *tmp)
{
	char	*tmp_prec;

	if (struc->precision.number > (int)ft_strlen(tmp))
	{
		if (!(tmp_prec = (char *)malloc(sizeof(char) *
						struc->precision.number)))
			return (0);
		tmp_prec = ft_memset(tmp_prec, 48, struc->precision.number -
				ft_strlen(tmp));
		tmp_prec[struc->precision.number - ft_strlen(tmp)] = '\0';
		tmp = ft_strjoin(tmp_prec, tmp);
	}
	if (struc->flag.negatif == 1)
		tmp = ft_strjoin("-", tmp);
	else if (struc->flag.plus == 1)
		tmp = ft_strjoin("+", tmp);
	else if (struc->flag.espace == 1)
		tmp = ft_strjoin(" ", tmp);
	if (struc->width.number > (int)ft_strlen(tmp))
		tmp = ft_largeur(struc, tmp);
	return (tmp);
}

static char	*ft_if_no_precision(t_struc *struc, char *tmp)
{
	if (struc->flag.negatif == 1)
		tmp = ft_strjoin("-", tmp);
	else if (struc->flag.plus == 1)
		tmp = ft_strjoin("+", tmp);
	else if (struc->flag.espace == 1)
		tmp = ft_strjoin(" ", tmp);
	if (struc->width.number > (int)ft_strlen(tmp))
		tmp = ft_largeur(struc, tmp);
	return (tmp);
}

int			write_d_and_i(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	tmp = modif_longeur(struc, ap);
	*buf = ft_remalloc(*buf, len->len_str + ft_strlen(tmp));
	if (struc->flag.zero == 1 && (struc->flag.plus == 1 || struc->flag.espace
				== 1 || struc->flag.negatif == 1) && struc->width.number > 0
			&& struc->precision.number == -1 && struc->flag.tiret == 0)
	{
		struc->precision.number = struc->width.number - 1;
		struc->width.number = 0;
	}
	if (struc->precision.number != -1)
		tmp = ft_if_precision(struc, tmp);
	else
		tmp = ft_if_no_precision(struc, tmp);
	len->len_str += ft_strlen(tmp);
	len->pos_buf += ft_strlen(tmp);
	ft_remalloc(*buf, len->len_str);
	ft_strcat(*buf, tmp);
	free(tmp);
	return (0);
}
