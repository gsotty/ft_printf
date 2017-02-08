/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:34:00 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/08 12:23:09 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*modif_longeur(t_struc *struc, va_list ap)
{
	if (struc->lenght.h == 1)
		return (ft_itoa((short)va_arg(ap, intmax_t)));
	else if (struc->lenght.hh == 1)
		return (ft_itoa((char)va_arg(ap, intmax_t)));
	else if (struc->lenght.l == 1)
		return (ft_long_itoa_base((long)va_arg(ap, intmax_t), 10));
	else if (struc->lenght.ll == 1)
		return (ft_intmax_t_itoa_base((long long)va_arg(ap, intmax_t), 10));
	else if (struc->lenght.j == 1)
		return (ft_intmax_t_itoa_base((intmax_t)va_arg(ap, intmax_t), 10));
	else if (struc->lenght.z == 1)
		return (ft_unsigned_itoa_base((size_t)va_arg(ap, intmax_t), 10));
	else
		return (ft_long_itoa_base(va_arg(ap, long), 10));
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

static char	*ft_if_precision(t_struc *struc, char *tmp, t_len *len)
{
	char	*tmp_prec;

	if (struc->precision.number >= len->len_tmp)
	{
		if (!(tmp_prec = (char *)malloc(sizeof(char) *
						struc->precision.number)))
			return (0);
		tmp_prec = ft_memset(tmp_prec, 48, struc->precision.number -
				len->len_tmp);
		tmp_prec[struc->precision.number - len->len_tmp] = '\0';
		tmp = ft_strjoin(tmp_prec, tmp);
		len->len_tmp = struc->precision.number;
	}
	if (struc->flag.plus == 1)
	{
		tmp = ft_strjoin("+", tmp);
		len->len_tmp += 1;
	}
	else if (struc->flag.espace == 1)
	{
		tmp = ft_strjoin(" ", tmp);
		len->len_tmp += 1;
	}
	if (struc->width.number >= len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp);
		len->len_str = ((len->len_buf) - (len->pos_str - (len->y - 1)))
			+ struc->width.number;
	}
	else
		len->len_str = ((len->len_buf) - (len->pos_str - (len->y - 1)))
			+ len->len_tmp;
	return (tmp);
}

static char	*ft_if_no_precision(t_struc *struc, char *tmp, t_len *len)
{
	if (struc->flag.plus == 1)
	{
		tmp = ft_strjoin("+", tmp);
		len->len_tmp += 1;
	}
	else if (struc->flag.espace == 1)
	{
		tmp = ft_strjoin(" ", tmp);
		len->len_tmp += 1;
	}
	if (struc->width.number >= len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp);
		len->len_str = ((len->len_buf) - (len->pos_str - (len->y - 1)))
			+ struc->width.number;
	}
	else
		len->len_str = ((len->len_buf) - (len->pos_str - (len->y - 1)))
			+ len->len_tmp;
	return (tmp);
}

int			write_dm(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	tmp = modif_longeur(struc, ap);
	len->len_tmp = ft_strlen(tmp);
	if (struc->flag.zero == 1 && (struc->flag.plus == 1 || struc->flag.espace
				== 1) && struc->width.number > 0 && struc->precision.number
			== -1 && struc->flag.tiret == 0)
	{
		struc->precision.number = struc->width.number - 1;
		struc->width.number = 0;
	}
	if (struc->precision.number != -1)
		tmp = ft_if_precision(struc, tmp, len);
	else
		tmp = ft_if_no_precision(struc, tmp, len);
	len->pos_buf += struc->width.number + len->pos_buf;
	ft_remalloc(*buf, len->len_str);
	ft_strcat(*buf, tmp);
	len->len_tmp = 0;
	free(tmp);
	return (0);
}
