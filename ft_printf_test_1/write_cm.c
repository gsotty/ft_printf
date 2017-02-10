/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/10 14:19:24 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

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
	tmp_spaces[struc->width.number - ft_strlen(tmp)] = '\0';
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

int			write_cm(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;
	wchar_t	tmp_va;

	tmp_va = (wchar_t)va_arg(ap, int);
	tmp = ft_strnew(4);
	len->len_tmp = ft_wctomb(tmp, tmp_va);
	*buf = ft_remalloc(*buf, len->len_str + 1, len->pos_buf);
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	len->len_str += len->len_tmp;
	ft_remalloc(*buf, len->len_str, len->pos_buf);
	ft_memmove(*buf + len->pos_buf, tmp, len->len_tmp);
	len->pos_buf += len->len_tmp;
	free(tmp);
	return (0);
}
