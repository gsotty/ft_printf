/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/14 10:40:29 by gsotty           ###   ########.fr       */
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
	if (struc->flag.zero == 1 && (struc->flag.tiret == 0))
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

int			write_c(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	if (struc->lenght.l == 1)
	{
		len->len_tmp = write_cm(struc, buf, len, ap);
		return (len->len_tmp);
	}
	tmp = ft_strnew(2);
	tmp[0] = (char)va_arg(ap, char *);
	tmp[1] = '\0';
	len->len_tmp = 1;
	*buf = ft_remalloc(*buf, len->len_str + 1, len->pos_buf);
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	len->len_str += len->len_tmp;
	ft_remalloc(*buf, len->len_str, len->pos_buf);
	ft_memmove(*buf + len->pos_buf, tmp, len->len_tmp);
	free(tmp);
	return (len->len_tmp);
}
