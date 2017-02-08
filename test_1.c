/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:54:05 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/08 14:06:54 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <locale.h>

void		verif_line_2(t_struc *struc, const char *str, int z, int y)
{
	check_flag(struc, str, z, y);
	check_width(struc, str, z, y);
	check_precision(struc, str, z, y);
	check_lenght(struc, str, z, y);
}

char		*verif_line(t_len *len, const char *str, char *buf, va_list ap)
{
	t_struc	struc;

	len->y = 0;
	while (len->pos_str < len->len_str)
	{
		if (str[len->pos_str] == '%' && (len->y = len->pos_str + 1))
		{
			ft_bzero(&struc, sizeof(t_struc));
			if (!(len->pos_str = check_specifier(&struc, str,
							len->pos_str + 1)))
				return (NULL);
			verif_line_2(&struc, str, len->pos_str, len->y);
			len->pos_str++;
			write_buf(&struc, &buf, len, ap);
		}
		else
		{
			buf = ft_remalloc(buf, len->pos_buf + 1);
			buf[len->pos_buf++] = str[len->pos_str++];
			buf[len->pos_buf] = '\0';
		}
	}
	return (buf);
}

int			ft_printf(const char *str, ...)
{
	t_len	len;
	va_list	ap;
	char	*buf;

	ft_bzero(&len, sizeof(t_len));
	len.len_str = ft_strlen((char *)str);
	va_start(ap, str);
	if ((buf = ft_strnew(len.len_str)) == NULL)
		return (-1);
	len.len_buf = len.len_str;
	buf = ft_memset(buf, len.len_str, 0);
	if ((buf = verif_line(&len, str, buf, ap)) == NULL)
		return (-1);
	ft_putstr(buf);
	va_end(ap);
	len.len_buf = ft_strlen(buf);
	return (len.len_buf);
}
