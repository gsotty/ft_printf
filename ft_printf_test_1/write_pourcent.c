/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pourcent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:57:16 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/27 17:11:44 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_largeur(t_struc *struc, char *tmp)
{
	char	*tmp_spaces;

	if (!(tmp_spaces = (char *)malloc(sizeof(char) * struc->width.number)))
		return (0);
	if (struc->flag.zero == 1 && struc->flag.tiret == 0)
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

int			write_pourcent(t_struc *struc, char **buf, t_len *len)
{
	char	*tmp;

	tmp = ft_strnew(2);
	tmp[0] = '%';
	tmp[1] = '\0';
	if (struc->width.number != 0)
		tmp = ft_largeur(struc, tmp);
	len->len_str += ft_strlen(tmp);
	len->pos_buf += ft_strlen(tmp);
	ft_remalloc(*buf, len->len_str);
	ft_strcat(*buf, tmp);
	free(tmp);
	return (0);
}