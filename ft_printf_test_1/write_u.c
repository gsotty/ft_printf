/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:14:12 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/14 10:52:14 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*modif_longeur(t_struc *struc, va_list ap)
{
	if (struc->lenght.h == 1)
		return (ft_unsigned_itoa((unsigned short)va_arg(ap, uintmax_t)));
	else if (struc->lenght.hh == 1)
		return (ft_unsigned_itoa((unsigned char)va_arg(ap, uintmax_t)));
	else if (struc->lenght.l == 1)
		return (ft_unsigned_long_itoa_base((long)va_arg(ap, uintmax_t), 10));
	else if (struc->lenght.ll == 1)
		return (ft_uintmax_t_itoa_base((long long)va_arg(ap, uintmax_t), 10));
	else if (struc->lenght.j == 1)
		return (ft_uintmax_t_itoa_base(va_arg(ap, uintmax_t), 10));
	else if (struc->lenght.z == 1)
		return (ft_unsigned_long_itoa_base((size_t)va_arg(ap, uintmax_t), 10));
	else
		return (ft_unsigned_itoa((unsigned int)va_arg(ap, unsigned int)));
}

static char	*ft_largeur(t_struc *struc, char *tmp, t_len *len)
{
	int		tmp_int;
	char	*tmp_spaces;

	tmp_int = struc->width.number - len->len_tmp;
	if (!(tmp_spaces = (char *)malloc(sizeof(char) * struc->width.number)))
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
		ft_remalloc(tmp_spaces, struc->width.number, tmp_int);
		ft_memmove(tmp_spaces + tmp_int, tmp, len->len_tmp);
		tmp = ft_strdup(tmp_spaces);
	}
	free(tmp_spaces);
	return (tmp);
}

static char	*ft_if_precision(t_struc *struc, char *tmp, t_len *len)
{
	char	*tmp_prec;

	tmp_prec = NULL;
	if (struc->precision.number > len->len_tmp)
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
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	len->len_str += len->len_tmp;
	free(tmp_prec);
	return (tmp);
}

static char	*ft_if_no_precision(t_struc *struc, char *tmp, t_len *len)
{
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	len->len_str += len->len_tmp;
	return (tmp);
}

int			write_u(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	tmp = modif_longeur(struc, ap);
	len->len_tmp = ft_strlen(tmp);
	if (ft_atoi(tmp) == 0 && struc->precision.number != -1 &&
			struc->width.number == 0)
		len->len_tmp = 0;
	*buf = ft_remalloc(*buf, len->len_str + len->len_tmp, len->pos_buf);
	if (struc->precision.number != -1)
		tmp = ft_if_precision(struc, tmp, len);
	else
		tmp = ft_if_no_precision(struc, tmp, len);
	ft_remalloc(*buf, len->len_str, len->pos_buf);
	ft_memmove(*buf + len->pos_buf, tmp, len->len_tmp);
	free(tmp);
	return (len->len_tmp);
}
