/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:39:24 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/27 14:50:46 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	tmp = ft_strjoin("0x", tmp);
	if (struc->width.number > (int)ft_strlen(tmp))
		tmp = ft_largeur(struc, tmp);
	return (tmp);
}

static char	*ft_if_no_precision(t_struc *struc, char *tmp)
{
	tmp = ft_strjoin("0x", tmp);
	if (struc->width.number > (int)ft_strlen(tmp))
		tmp = ft_largeur(struc, tmp);
	return (tmp);
}

int			write_p(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	tmp = ft_long_itoa_base((long)va_arg(ap, void *), 16);
	*buf = ft_remalloc(*buf, len->len_str + ft_strlen(tmp));
	if (struc->flag.zero == 1 && struc->width.number > 0 &&
			struc->precision.number == -1 && struc->flag.tiret == 0)
	{
		struc->precision.number = struc->width.number - 2;
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