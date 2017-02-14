/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_xm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:55:26 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/14 06:30:50 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_largeur(t_struc *struc, char *tmp, t_len *len)
{
	int		tmp_int;
	char	*tmp_spaces;

	tmp_int = struc->width.number - len->len_tmp;
	if (!(tmp_spaces = (char *)malloc(sizeof(char) * tmp_int)))
		return (0);
	if (struc->flag.zero && (struc->flag.tiret == 0) &&
			(struc->precision.number == -1))
		tmp_spaces = ft_memset(tmp_spaces, 48, tmp_int);
	else
		tmp_spaces = ft_memset(tmp_spaces, 32, tmp_int);
	tmp_spaces[tmp_int] = '\0';
	if (struc->flag.tiret)
	{
		ft_remalloc(tmp, struc->width.number, len->len_tmp);
		ft_memmove(tmp + len->len_tmp, tmp_spaces, tmp_int);
	}
	else
	{
		tmp_spaces = ft_remalloc(tmp_spaces, struc->width.number, tmp_int);
		ft_memmove(tmp_spaces + tmp_int, tmp, len->len_tmp);
		tmp = ft_strdup(tmp_spaces);
	}
	return (tmp);
}

static char	*ft_if_precision(t_struc *struc, char *tmp, t_len *len)
{
	char	*tmp_prec;

	if (struc->precision.number > len->len_tmp)
	{
		if (!(tmp_prec = (char *)malloc(sizeof(char) *
						struc->precision.number)))
			return (0);
		tmp_prec = ft_memset(tmp_prec, 48, struc->precision.number -
				len->len_tmp);
		tmp_prec[struc->precision.number - len->len_tmp] = '\0';
		ft_flag(tmp, len, tmp_prec, struc->precision.number - len->len_tmp);
	}
	if (struc->flag.diese == 1)
		tmp = ft_flag(tmp, len, "0X", 2);
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	len->len_str += len->len_tmp;
	return (tmp);
}

static char	*ft_if_no_precision(t_struc *struc, char *tmp, t_len *len)
{
	if (struc->flag.diese == 1)
		tmp = ft_flag(tmp, len, "0X", 2);
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	len->len_str += len->len_tmp;
	return (tmp);
}

int			write_xm(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	tmp = modif_longeur_xm(struc, ap);
	len->len_tmp = ft_strlen(tmp);
	if (struc->flag.negatif == 1)
		struc->flag.diese = 0;
	if (struc->flag.negatif == 1 && (struc->precision.number != -1 ||
				struc->width.number != 0))
		len->len_tmp = 0;
	if (struc->flag.zero == 1 && (struc->flag.plus == 1 || struc->flag.espace
				== 1 || struc->flag.diese == 1) && struc->width.number > 0
			&& struc->precision.number == -1 && struc->flag.tiret == 0)
	{
		struc->precision.number = struc->width.number - 2;
		struc->width.number = 0;
	}
	*buf = ft_remalloc(*buf, len->pos_buf + len->len_tmp, len->pos_buf);
	if (struc->precision.number != -1)
		tmp = ft_if_precision(struc, tmp, len);
	else
		tmp = ft_if_no_precision(struc, tmp, len);
	*buf = ft_remalloc(*buf, len->pos_buf + len->len_tmp, len->pos_buf);
	ft_memmove(*buf + len->pos_buf, tmp, len->len_tmp);
	return (len->len_tmp);
}
