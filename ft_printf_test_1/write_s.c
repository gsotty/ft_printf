/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:38:22 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/10 15:39:04 by gsotty           ###   ########.fr       */
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
	if (struc->flag.zero && (struc->flag.tiret == 0))
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
		tmp_spaces = ft_remalloc(tmp_spaces, struc->width.number, tmp_int);
		ft_memmove(tmp_spaces + tmp_int, tmp, len->len_tmp);
		tmp = ft_strdup(tmp_spaces);
	}
	return (tmp);
}

static char	*ft_if_precision(t_struc *struc, char *tmp, t_len *len)
{
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

int			write_s(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	if (struc->lenght.l == 1)
	{
		write_sm(struc, buf, len, ap);
		return (0);
	}
	tmp = va_arg(ap, char *);
	if (tmp == NULL)
		tmp = "(null)";
	len->len_tmp = ft_strlen(tmp);
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
