/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/08 11:08:12 by gsotty           ###   ########.fr       */
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

int			write_cm(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;
	wchar_t	*tmp_va;

	tmp = ft_strnew(4);
	tmp_va = (wchar_t *)ft_strnew(2);
	tmp_va[0] = va_arg(ap, int);
	tmp_va[1] = '\0';
	ft_wcstombs(tmp, tmp_va, 4);
	if (struc->width.number >= 1)
	{
		tmp = ft_largeur(struc, tmp);
		len->len_buf = ((len->len_buf) - (len->pos_str - (len->y - 1)))
			+ struc->width.number;
	}
	else
		len->len_buf = ((len->len_buf) - (len->pos_str - (len->y - 1))) + 1;
	len->pos_buf = struc->width.number + len->pos_buf;
	ft_remalloc(*buf, len->len_buf);
	ft_strcat(*buf, tmp);
	free(tmp);
	return (0);
}
