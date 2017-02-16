/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:38:22 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/16 16:13:29 by gsotty           ###   ########.fr       */
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
			struc->precision.number <= 0)
		ft_memset(tmp_spaces, 48, tmp_int);
	else
		ft_memset(tmp_spaces, 32, tmp_int);
	tmp_spaces[struc->width.number - len->len_tmp] = '\0';
	if (struc->flag.tiret)
	{
		tmp = ft_remalloc(tmp, struc->width.number, len->len_tmp);
		ft_memmove(tmp + len->len_tmp, tmp_spaces, tmp_int);
	}
	else
	{
		tmp_spaces = ft_remalloc(tmp_spaces, struc->width.number, tmp_int);
		ft_memmove(tmp_spaces + tmp_int, tmp, len->len_tmp);
		tmp = ft_memalloc(struc->width.number);
		ft_memcpy(tmp, tmp_spaces, struc->width.number);
	}
	free(tmp_spaces);
	return (tmp);
}

static char	*ft_if_precision(t_struc *struc, char *tmp, t_len *len)
{
	char	*tmp_char;

	tmp_char = NULL;
	if (struc->precision.number <= len->len_tmp)
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
	len->len_str += len->len_tmp;
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

char		*write_s(t_struc *struc, char *buf, t_len *len, va_list ap)
{
	char	*tmp;
	char	*tmp_va;

	tmp  = NULL;
	if (struc->lenght.l == 1)
	{
		buf = write_sm(struc, buf, len, ap);
		return (buf);
	}
	tmp_va = va_arg(ap, char *);
	if (tmp_va == NULL)
	{
		tmp = ft_memalloc(7);
		ft_memcpy(tmp, "(null)", 7);
		len->len_tmp = 6;
	}
	else
	{
		tmp = ft_memalloc(ft_strlen(tmp_va));
		ft_memcpy(tmp, tmp_va, ft_strlen(tmp_va));
		tmp[ft_strlen(tmp_va)] = '\0';
		len->len_tmp = ft_strlen(tmp);
	}
	if (tmp[0] == '\0')
		struc->precision.number = -1;
	if (struc->precision.number != -1)
		tmp = ft_if_precision(struc, tmp, len);
	else
		tmp = ft_if_no_precision(struc, tmp, len);
	buf = ft_remalloc(buf, len->pos_buf + len->len_tmp, len->pos_buf);
	buf = ft_remalloc(buf, len->pos_buf + len->len_tmp, len->pos_buf);
	ft_memcpy(buf + len->pos_buf, tmp, len->len_tmp);
	len->pos_buf += len->len_tmp;
	free(tmp);
	return (buf);
}
