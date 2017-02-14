/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:54:05 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/14 08:53:58 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <locale.h>

static void	verif_line_2(t_struc *struc, const char *str, int z, int y)
{
	check_flag(struc, str, z, y);
	check_width(struc, str, z, y);
	check_precision(struc, str, z, y);
	check_lenght(struc, str, z, y);
}

static void	ft_no_pourcent(t_len *len, const char *str, char **buf)
{
	char	*tmp_buf;

	tmp_buf = *buf;
	if (len->pos_buf > len->pos_str)
		tmp_buf = ft_remalloc(tmp_buf, len->pos_buf + 1, len->pos_buf);
	tmp_buf[len->pos_buf++] = str[len->pos_str++];
	tmp_buf[len->pos_buf] = '\0';
	*buf = tmp_buf;
}

static void	verif_line(t_len *len, const char *str, char **buf, va_list ap)
{
	int		y;
	t_struc	struc;

	y = 0;
	while (str[len->pos_str] != '\0')
	{
		if (str[len->pos_str] == '%' && (y = len->pos_str + 1))
		{
			ft_bzero(&struc, sizeof(t_struc));
			if ((len->pos_str = check_specifier(&struc, str, len->pos_str + 1)))
			{
				verif_line_2(&struc, str, len->pos_str, y);
				write_buf(&struc, buf, len, ap);
				len->pos_str++;
			}
		}
		else
			ft_no_pourcent(len, str, buf);
	}
}

int			ft_printf(const char *str, ...)
{
	t_len	len;
	va_list	ap;
	char	*buf;

	ft_bzero(&len, sizeof(t_len));
	len.len_str = ft_strlen((char *)str) + 1;
	va_start(ap, str);
	if ((buf = ft_memalloc(len.len_str)) == NULL)
		return (-1);
	ft_memset(buf, len.len_str, 0);
	verif_line(&len, str, &buf, ap);
	ft_putnstr(buf, len.pos_buf);
	if (len.null == 1)
		len.pos_buf = -1;
	va_end(ap);
	free(buf);
	return (len.pos_buf);
}
