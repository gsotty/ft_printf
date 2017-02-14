/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d_and_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:42:10 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/14 10:39:04 by gsotty           ###   ########.fr       */
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

static char	*ft_flag(t_struc *struc, char *tmp, t_len *len, char *tmp_char)
{
	if (struc->flag.negatif == 1)
	{
		tmp_char = ft_strdup("-");
		ft_remalloc(tmp_char, len->len_tmp + 1, 1);
		ft_memmove(tmp_char + 1, tmp, len->len_tmp + 1);
		tmp = ft_strdup(tmp_char);
		len->len_tmp++;
	}
	else if (struc->flag.plus == 1)
	{
		tmp_char = ft_strdup("+");
		ft_remalloc(tmp_char, len->len_tmp + 1, 1);
		ft_memmove(tmp_char + 1, tmp, len->len_tmp + 1);
		tmp = ft_strdup(tmp_char);
		len->len_tmp++;
	}
	else if (struc->flag.espace == 1)
	{
		tmp_char = ft_strdup(" ");
		ft_remalloc(tmp_char, len->len_tmp + 1, 1);
		ft_memmove(tmp_char + 1, tmp, len->len_tmp + 1);
		tmp = ft_strdup(tmp_char);
		len->len_tmp++;
	}
	return (tmp);
}

static char	*ft_if_precision(t_struc *struc, char *tmp, t_len *len)
{
	char	*tmp_char;
	char	*tmp_prec;

	tmp_char = NULL;
	tmp_prec = NULL;
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
	tmp = ft_flag(struc, tmp, len, tmp_char);
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	len->len_str += len->len_tmp;
	free(tmp_prec);
	free(tmp_char);
	return (tmp);
}

static char	*ft_if_no_precision(t_struc *struc, char *tmp, t_len *len)
{
	char	*tmp_char;

	tmp_char = NULL;
	tmp = ft_flag(struc, tmp, len, tmp_char);
	if (struc->width.number > len->len_tmp)
	{
		tmp = ft_largeur(struc, tmp, len);
		len->len_tmp = struc->width.number;
	}
	len->len_str += len->len_tmp;
	free(tmp_char);
	return (tmp);
}

int			write_d_and_i(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	tmp = modif_longeur_d_and_i(struc, ap);
	len->len_tmp = ft_strlen(tmp);
	if (ft_atoi(tmp) == 0 && struc->precision.number != -1
				&& struc->width.number != 0 && struc->flag.zero != 1)
		tmp[0] = ' ';
	if (ft_atoi(tmp) == 0 && struc->precision.number != -1
				&& struc->width.number == 0)
		len->len_tmp = 0;
	if (struc->flag.zero == 1 && (struc->flag.plus == 1 || struc->flag.espace
				== 1 || struc->flag.negatif == 1) && struc->width.number > 0
			&& struc->precision.number == -1 && struc->flag.tiret == 0)
	{
		struc->precision.number = struc->width.number - 1;
		struc->width.number = 0;
	}
	*buf = ft_remalloc(*buf, len->len_str + len->len_tmp, len->pos_buf);
	if (struc->precision.number != -1)
		tmp = ft_if_precision(struc, tmp, len);
	else
		tmp = ft_if_no_precision(struc, tmp, len);
	ft_remalloc(*buf, len->len_str, len->pos_buf);
	ft_memmove(*buf + len->pos_buf, tmp, len->len_tmp);
	free(tmp);
	return (len->len_tmp);
}
