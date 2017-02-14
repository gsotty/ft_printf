/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:24:07 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/14 06:30:02 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*modif_longeur(t_struc *struc, va_list ap)
{
	if (struc->lenght.h == 1)
		return (ft_itoa_base((unsigned short)va_arg(ap, int), 8));
	else if (struc->lenght.hh == 1)
		return (ft_itoa_base((unsigned char)va_arg(ap, int), 8));
	else if (struc->lenght.l == 1)
		return (ft_uintmax_t_itoa_base(va_arg(ap, unsigned long), 8));
	else if (struc->lenght.ll == 1)
		return (ft_uintmax_t_itoa_base(va_arg(ap, uintmax_t), 8));
	else if (struc->lenght.j == 1)
		return (ft_uintmax_t_itoa_base(va_arg(ap, uintmax_t), 8));
	else if (struc->lenght.z == 1)
		return (ft_unsigned_long_itoa_base((size_t)va_arg(ap, intmax_t), 8));
	else
		return (ft_unsigned_long_itoa_base(va_arg(ap, unsigned int), 8));
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
		tmp = ft_strjoin(tmp_prec, tmp);
		len->len_tmp = struc->precision.number;
	}
	if (struc->flag.diese == 1)
		tmp = ft_flag(tmp, len, "0", 1);
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
		tmp = ft_flag(tmp, len, "0", 1);
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	len->len_str += len->len_tmp;
	return (tmp);
}

int			write_o(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	tmp = modif_longeur(struc, ap);
	len->len_tmp = ft_strlen(tmp);
	if (ft_atoi(tmp) == 0 && (struc->width.number != 0 ||
				struc->precision.number != -1) && struc->flag.diese != 1)
		len->len_tmp = 0;
	if (ft_atoi(tmp) == 0)
		struc->flag.diese = 0;
	if (struc->flag.diese == 1 && struc->precision.number > 0)
		struc->precision.number = struc->precision.number - 1;
	*buf = ft_remalloc(*buf, len->len_str + len->len_tmp, len->pos_buf);
	if (struc->precision.number != -1)
		tmp = ft_if_precision(struc, tmp, len);
	else
		tmp = ft_if_no_precision(struc, tmp, len);
	ft_remalloc(*buf, len->len_str, len->pos_buf);
	ft_memmove(*buf + len->pos_buf, tmp, len->len_tmp);
	return (len->len_tmp);
}
