/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:54:05 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/25 09:48:22 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int			cont_pour(const char *str)
{
	int		x;
	int		cont;

	x = 0;
	cont = 0;
	while (str[x] != 0)
	{
		if (str[x] == '%')
			cont++;
		x++;
	}
	return (cont);
}

int			width(t_struc *struc, char **buf, int len, int len_2)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * len)))
		return (0);
	if (struc->flag.zero == 1)
		tmp = ft_memset(tmp, '0', len);
	else
		tmp = ft_memset(tmp, ' ', len);
	if (len > len_2)
	{
		if (struc->flag.tiret == 1)
		{
			*buf = ft_strcat(*buf, tmp);
			struc->flag.tiret = 0;
		}
		else
		{
		}
	}
	struc->width.number = 0;
	return (len - len_2);
}

/*
** fontion qui va remplire le buf pour chaque '%' qui prend en paramaitre la
** struc, le buffer, la place ou je suit dans str et ap le va_list qui me
** permait de lire les multi arg
*/

int			write_pourcent(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;
	char	*tmp_buf;

	if (!(tmp_buf = (char *)malloc(sizeof(char) * len->len_str)))
		return (0);
	if (struc->width.number > 0)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * struc->width.number)))
			return (0);
		if (struc->flag.zero == 1)
		{
			tmp = ft_memset(tmp, '0', struc->width.number);
			struc->flag.zero = 0;
		}
		else
			tmp = ft_memset(tmp, ' ', struc->width.number);
		tmp[struc->width.number] = '%';
		tmp[struc->width.number + 1] = '\0';
		tmp_buf = ft_memcpy(tmp_buf, *buf, len->len_str);
		*buf = ft_remalloc(*buf, len->len_str + struc->width.number);
		*buf = ft_memcpy(*buf, tmp_buf, len->len_str);
		*buf = ft_strcat(*buf, tmp);
		len->pos_buf += 3;
		len->len_str += struc->width.number;
	}
	else
	{
		if (!(tmp = (char *)malloc(sizeof(char) * 2)))
			return (0);
		tmp[0] = '%';
		tmp[1] = '\0';
		tmp_buf = ft_memcpy(tmp_buf, *buf, len->pos_buf);
		*buf = ft_remalloc(*buf, len->len_str + 2);
		*buf = ft_memcpy(*buf, tmp_buf, len->len_str);
		*buf = ft_strcat(*buf, tmp);
		len->pos_buf += 1;
		len->len_str += 1;
	}
	return (1);
}

int			write_buf(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	int		tmp_int_s;
	char	*tmp_char_s;
	char	*tmp;

	tmp = NULL;
	tmp_int_s = 0;
	if (struc->specifier.pourcent == 1)
	{
		write_pourcent(struc, buf, len, ap);
		struc->specifier.pourcent = 0;
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.o == 1)
	{
		struc->specifier.o = 0;
		*buf = ft_strjoin(*buf, ft_unsigned_itoa_base(va_arg(ap,
						unsigned int), 8));
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.om == 1)
	{
		struc->specifier.om = 0;
		*buf = ft_strjoin(*buf, ft_unsigned_long_itoa_base(va_arg(ap,
						unsigned long), 8));
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.c == 1)
	{
		struc->specifier.c = 0;
		tmp[0] = (unsigned char)va_arg(ap, int);
		*buf = ft_strcat(*buf, tmp);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.x == 1)
	{
		struc->specifier.x = 0;
		*buf = ft_strjoin(*buf, ft_unsigned_itoa_base(va_arg(ap,
						unsigned int), 16));
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.xm == 1)
	{
		struc->specifier.xm = 0;
		*buf = ft_strjoin(*buf, ft_unsigned_itoa_base_m(va_arg(ap,
						unsigned int), 16));
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.d == 1 || struc->specifier.i == 1)
	{
		tmp_int_s = va_arg(ap, int);
		if (struc->flag.plus == 1)
			if (tmp_int_s > 0)
				tmp[0] = '+';
		struc->specifier.i = 0;
		struc->specifier.d = 0;
		*buf = ft_remalloc(*buf, len->len_str + ft_strlen(ft_itoa(tmp_int_s)));
		*buf = ft_strcat(*buf, ft_itoa(tmp_int_s));
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.u == 1)
	{
		struc->specifier.u = 0;
		*buf = ft_strjoin(*buf, ft_unsigned_itoa(va_arg(ap, unsigned int)));
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.s == 1)
	{
		tmp_char_s = va_arg(ap, char *);
		struc->specifier.s = 0;
		*buf = ft_remalloc(*buf, len->len_str + ft_strlen(tmp_char_s));
		*buf = ft_strcat(*buf, tmp_char_s);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.p == 1)
	{
		tmp = "0x";
		tmp_char_s = ft_long_itoa_base((long)va_arg(ap, void *), 16);
		tmp_char_s = ft_strjoin("0x", tmp_char_s);
		struc->specifier.p = 0;
		*buf = ft_remalloc(*buf, len->len_str + ft_strlen(tmp_char_s));
		*buf = ft_strcat(*buf, tmp_char_s);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	return (0);
}

/*
** check les flags { - | + | (space) | # | 0 }
** puis les width { (number) | * }
** ensuit la precision qui commense par un '.' suivit par { (number) | * }
** et pour finir la lenght { h | l | ll }
** aprait on regarde le specifier { s | S | p | d | D | i | o | O | u | U
** x | X | c | C } et si le specifier et un nouveau '%' afficher '%';
*/

void		verif_line_2(t_struc *struc, const char *str, int z, int y)
{
	check_flag(struc, str, z, y);
	check_width(struc, str, z, y);
	check_precision(struc, str, z, y);
	check_lenght(struc, str, z, y);
}

/*
** a la sortie de verif_line_2 j'ai ma struc avec les bon paramaitre pour le
** '%' le prmier pourcent
*/

char		*verif_line(t_len *len, const char *str, char *buf, va_list ap)
{
	int		y;
	t_struc	struc;

	y = 0;
	ft_bzero(&struc, sizeof(t_struc));
	while (str[len->pos_str] != '\0')
	{
		if (str[len->pos_str] == '%' && (y = len->pos_str + 1))
		{
			if (!(len->pos_str = check_specifier(&struc, str, len->pos_str + 1)))
				return (NULL);
			verif_line_2(&struc, str, len->pos_str, y);
			write_buf(&struc, &buf, len, ap);
			len->pos_str++;
		}
		else
		{
			buf[len->pos_buf++] = str[len->pos_str++];
		}
//		ft_putnbr(len->pos_buf);
//		ft_putstr("\n");
//		ft_putstr((char *)str + len->pos_buf);
//		ft_putstr("\n");
//		ft_putstr(buf);
//		ft_putstr("\n");
	}
	return (buf);
}

void		test(const char *str, ...)
{
	t_len	len;
	va_list	ap;
	char	*buf;

	ft_bzero(&len, sizeof(t_len));
	len.len_str = ft_strlen(str);
	va_start(ap, str);
	if ((buf = ft_strnew(len.len_str)) == NULL)
		return ;
	buf = ft_memset(buf, len.len_str, 0);
	if ((buf = verif_line(&len, str, buf, ap)) == NULL)
		return ;
	ft_putstr(buf);
	ft_putstr("\n");
	va_end(ap);
}

/*
** argv[1] == "la string entre en paramaitre de printf"
*/

int			main(int argc, char **argv)
{
	printf("printf: ");
	printf(argv[1], ft_atoi(argv[2]), argv[3]);
	printf("\n");
	ft_putstr("ft_printf: ");
	test((const char *)argv[1], ft_atoi(argv[2]), argv[3]);
	return (0);
}
