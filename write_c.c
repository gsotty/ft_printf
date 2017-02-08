/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/08 14:04:32 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_largeur(t_struc *struc, char *tmp, t_len *len)
{
	char	*tmp_spaces;

	if (!(tmp_spaces = (char *)malloc(sizeof(char) * struc->width.number)))
		return (0);
	if (struc->flag.zero && (struc->flag.tiret == 0) &&
			(struc->precision.number == -1))
		tmp_spaces = ft_memset(tmp_spaces, 48, struc->width.number -
				len->len_tmp);
	else
		tmp_spaces = ft_memset(tmp_spaces, 32, struc->width.number -
				len->len_tmp);
	tmp_spaces[struc->width.number - len->len_tmp] = '\0';
	if (struc->flag.tiret)
		tmp = ft_strjoin(tmp, tmp_spaces);
	else
		tmp = ft_strjoin(tmp_spaces, tmp);
	return (tmp);
}

int			write_c(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	tmp = ft_strnew(2);
	len->len_tmp = 1;
	tmp[0] = (char)va_arg(ap, char *);
	tmp[1] = '\0';
	if (struc->width.number >= 1)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_buf = ((len->len_buf) - (len->pos_str - (len->y - 1)))
			+ struc->width.number;
	}
	else
		len->len_buf = ((len->len_buf)  - (len->pos_str - (len->y - 1)))
			+ len->len_tmp;
	len->pos_buf += struc->width.number;
	ft_remalloc(*buf, len->len_buf);
	ft_strcat(*buf, tmp);
	len->len_tmp = 0;
	free(tmp);
	return (0);
}
