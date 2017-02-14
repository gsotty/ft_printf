/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pourcent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:57:16 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/14 08:39:45 by gsotty           ###   ########.fr       */
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
	if (struc->flag.zero == 1 && struc->flag.tiret == 0)
		tmp_spaces = ft_memset(tmp_spaces, 48, tmp_int);
	else
		tmp_spaces = ft_memset(tmp_spaces, 32, tmp_int);
	tmp_spaces[tmp_int] = '\0';
	if (struc->flag.tiret)
	{
		ft_remalloc(tmp, struc->width.number, len->len_tmp);
		ft_memcpy(tmp + len->len_tmp, tmp_spaces, tmp_int);
	}
	else
	{
		ft_remalloc(tmp_spaces, struc->width.number, tmp_int);
		ft_memcpy(tmp_spaces + tmp_int, tmp, len->len_tmp);
		tmp = ft_strdup(tmp_spaces);
	}
	free(tmp_spaces);
	return (tmp);
}

int			write_pourcent(t_struc *struc, char **buf, t_len *len)
{
	char	*tmp;

	tmp = ft_strnew(2);
	tmp[0] = '%';
	tmp[1] = '\0';
	len->len_tmp = 1;
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	len->len_str += len->len_tmp;
	*buf = ft_remalloc(*buf, len->pos_buf + len->len_tmp, len->pos_buf);
	ft_memmove(*buf + len->pos_buf, tmp, len->len_tmp);
	free(tmp);
	return (len->len_tmp);
}
