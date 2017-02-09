/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:38:22 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/09 17:17:42 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	tmp_spaces[struc->width.number - len->len_tmp] = '\0';
	if (struc->flag.tiret)
	{
		tmp = ft_remalloc(tmp, struc->width.number, len->len_tmp);
		ft_memmove(tmp + len->len_tmp, tmp_spaces, tmp_int);
	}
	else
	{
		tmp = ft_remalloc(tmp, struc->width.number, tmp_int);
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
		tmp_prec = ft_memset(tmp_prec, 32, struc->precision.number -
				len->len_tmp);
		tmp_prec[struc->precision.number - len->len_tmp] = '\0';
		tmp = ft_strjoin(tmp_prec, tmp);
		len->len_tmp = struc->precision.number;
	}
	else
	{
		tmp = ft_remalloc(tmp, struc->precision.number, len->len_tmp);
		tmp[struc->precision.number] = '\0';
		len->len_tmp = struc->precision.number;
	}
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	return (tmp);
}

static char	*ft_if_no_precision(t_struc *struc, char *tmp, t_len *len)
{
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	return (tmp);
}

int			write_sm(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	size_t	x;
	char	*tmp;
	wchar_t	*tmp_va;

	tmp_va = va_arg(ap, int *);
	if (tmp_va == NULL)
	{
		tmp = "(null)";
		len->len_tmp = ft_strlen(tmp);
	}
	else
	{
		x = ft_wcslen(tmp_va);
		tmp = ft_memalloc(x);
		len->len_tmp = ft_wcstombs(tmp, tmp_va, x);
	}
	if (tmp[0] == '\0')
		struc->precision.number = -1;
	*buf = ft_remalloc(*buf, len->len_str + len->len_tmp, len->pos_buf);
	if (struc->precision.number != -1)
		tmp = ft_if_precision(struc, tmp, len);
	else
		tmp = ft_if_no_precision(struc, tmp, len);
	len->len_str += len->len_tmp;
	*buf = ft_remalloc(*buf, len->len_str, len->pos_buf);
	ft_memmove(*buf + len->pos_buf, tmp, len->len_tmp);
	len->pos_buf += len->len_tmp;
	return (0);
}
