/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:54:05 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/27 17:05:24 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** fontion qui va remplire le buf pour chaque '%' qui prend en paramaitre la
** struc, le buffer, la place ou je suit dans str et ap le va_list qui me
** permait de lire les multi arg
*/

int			write_buf(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	tmp = NULL;
	if (struc->specifier.s == 1)
	{
		write_s(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.sm == 1) // nn fait
	{
		return (1);
	}
	if (struc->specifier.p == 1)
	{
		write_p(struc, buf, len, ap);
		return (1);
	}
	if (struc->specifier.d == 1)
	{
		write_d_and_i(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.dm == 1)
	{
		write_dm(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.i == 1)
	{
		write_d_and_i(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.o == 1)
	{
		write_o(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.om == 1)
	{
		write_om(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.u == 1)
	{
		write_u(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.um == 1)
	{
		write_um(struc, buf, len, ap);
		return (1);
	}
	if (struc->specifier.x == 1)
	{
		write_x(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.xm == 1)
	{
		write_xm(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.c == 1) // nn fait
	{
		write_c(struc, buf, len, ap);
	//	tmp[0] = (unsigned char)va_arg(ap, int);
	//	*buf = ft_strcat(*buf, tmp);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.cm == 1) // nn fait
	{
		return (1);
	}
	if (struc->specifier.pourcent == 1)
	{
		write_pourcent(struc, buf, len);
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
	while (str[len->pos_str] != '\0')
	{
		if (str[len->pos_str] == '%' && (y = len->pos_str + 1))
		{
			ft_bzero(&struc, sizeof(t_struc));
			if (!(len->pos_str = check_specifier(&struc, str,
							len->pos_str + 1)))
				return (NULL);
			verif_line_2(&struc, str, len->pos_str, y);
			write_buf(&struc, &buf, len, ap);
			len->pos_str++;
		}
		else
		{
			buf = ft_remalloc(buf, len->pos_buf + 1);
			buf[len->pos_buf++] = str[len->pos_str++];
		}
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
	if (argc == 1)
		return (0);
	printf("printf:\t\t");
	printf(argv[1], ft_atoi(argv[2]), 'h');
	printf("\n");
	ft_putstr("ft_printf:\t");
	test((const char *)argv[1], ft_atoi(argv[2]), 'h');
	return (0);
}
