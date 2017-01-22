/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:54:05 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/22 14:24:28 by gsotty           ###   ########.fr       */
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

/*
** char		*after_diese(int *x, char str, char *buf, va_list ap)
**  {
**  	char	*tmp;
**  	int		len;
**
**  	len = ft_strlen(buf);
**  	if (str == 'c')
**  	{
**  		tmp = ft_strdup(buf);
**  		buf = ft_memalloc(len + 2);
**  		buf = ft_memcpy(buf, tmp, len);
**  		buf[len] = (char)va_arg(ap, int);
**  		buf[len + 1] = '\0';
**  		*x = ft_strlen(buf);
**  		return (buf);
**  	}
**  	if (str == 'o')
**  	{
**  		buf = ft_strjoin(buf, ft_itoa_base(va_arg(ap, unsigned int), 8));
**  		*x = ft_strlen(buf);
**  		return (buf);
**  	}
**  	if (str == 'x')
**  	{
**  		buf = ft_strjoin(buf, ft_unsigned_itoa_base(va_arg(ap,
**  						unsigned int), 16));
**  		*x = ft_strlen(buf);
**  		return (buf);
**  	}
**  	if (str == 'X')
**  	{
**  		buf = ft_strjoin(buf, ft_unsigned_itoa_base_m(va_arg(ap,
**  						unsigned int), 16));
**  		*x = ft_strlen(buf);
**  		return (buf);
**  	}
**  	if (str == 'd')
**  	{
**  		buf = ft_strjoin(buf, ft_itoa(va_arg(ap, int)));
**  		*x = ft_strlen(buf);
**  		return (buf);
**  	}
**  	if (str == 'u')
**  	{
**  		buf = ft_strjoin(buf, ft_unsigned_itoa(va_arg(ap, unsigned int)));
**  		*x = ft_strlen(buf);
**  		return (buf);
**  	}
**  	if (str == 'i')
**  	{
**  		buf = ft_strjoin(buf, ft_itoa(va_arg(ap, int)));
**  		*x = ft_strlen(buf);
**  		return (buf);
**  	}
**  	if (str == 's')
**  	{
**  		buf = ft_strjoin(buf, va_arg(ap, char *));
**  		*x = ft_strlen(buf);
**  		return (buf);
**  	}
**  	if (str == 'p')
**  	{
**  		buf = ft_strjoin(buf, ft_strjoin("0x", ft_itoa_base(va_arg(ap,
**  							int), 16)));
**  		*x = ft_strlen(buf);
**  		return (buf);
**  	}
**  	return (NULL);
**  }
*/

t_struc		*ft_malloc_struct(void)
{
	t_struc	*struc;

	if ((struc = (t_struc *)malloc(sizeof(t_struc))) == NULL)
		return (NULL);
	struc = ft_memset(struc, sizeof(struc), 0);
	if ((struc->flag = (t_flag *)malloc(sizeof(t_flag))) == NULL)
		return (NULL);
	struc->flag = ft_memset(struc->flag, sizeof(struc->flag), 0);
	if ((struc->width = (t_width *)malloc(sizeof(t_width))) == NULL)
		return (NULL);
	struc->width = ft_memset(struc->width, sizeof(struc->width), 0);
	if ((struc->precision = (t_precision *)malloc(sizeof(t_precision))) == NULL)
		return (NULL);
	struc->precision = ft_memset(struc->precision, sizeof(struc->precision), 0);
	if ((struc->lenght = (t_lenght *)malloc(sizeof(t_lenght))) == NULL)
		return (NULL);
	struc->lenght = ft_memset(struc->lenght, sizeof(struc->lenght), 0);
	if ((struc->specifier = (t_specifier *)malloc(sizeof(t_specifier))) == NULL)
		return (NULL);
	struc->specifier = ft_memset(struc->specifier, sizeof(struc->specifier), 0);
	return (struc);
}

int			check_specifier(t_struc *struc, const char *str, int z)
{
	while (str[z] != '\0')
	{
		if (str[z] == 'c')
		{
			struc->specifier->c = 1;
			return (z);
		}
		if (str[z] == 'C')
		{
			struc->specifier->cm = 1;
			return (z);
		}
		if (str[z] == 'd')
		{
			struc->specifier->d = 1;
			return (z);
		}
		if (str[z] == 'D')
		{
			struc->specifier->dm = 1;
			return (z);
		}
		if (str[z] == 'i')
		{
			struc->specifier->i = 1;
			return (z);
		}
		if (str[z] == 'o')
		{
			struc->specifier->o = 1;
			return (z);
		}
		if (str[z] == 'O')
		{
			struc->specifier->om = 1;
			return (z);
		}
		if (str[z] == 's')
		{
			struc->specifier->s = 1;
			return (z);
		}
		if (str[z] == 'S')
		{
			struc->specifier->sm = 1;
			return (z);
		}
		if (str[z] == 'u')
		{
			struc->specifier->u = 1;
			return (z);
		}
		if (str[z] == 'U')
		{
			struc->specifier->um = 1;
			return (z);
		}
		if (str[z] == 'x')
		{
			struc->specifier->x = 1;
			return (z);
		}
		if (str[z] == 'X')
		{
			struc->specifier->xm = 1;
			return (z);
		}
		if (str[z] == 'p')
		{
			struc->specifier->p = 1;
			return (z);
		}
		if (str[z] == '%')
		{
			struc->specifier->pourcent = 1;
			return (z);
		}
		z++;
	}
	return (0);
}

int			check_flag(t_struc *struc, const char *str, int z, int y)
{
	while (y < z)
	{
		if (str[y] == '-')
		{
			struc->flag->tiret = 1;
			return (1);
		}
		if (str[y] == '+')
		{
			struc->flag->plus = 1;
			return (1);
		}
		if (str[y] == ' ')
		{
			struc->flag->espace = 1;
			return (1);
		}
		if (str[y] == '#')
		{
			struc->flag->diese = 1;
			return (1);
		}
		if (str[y] == '0')
		{
			struc->flag->zero = 1;
			return (1);
		}
		y++;
	}
	return (0);
}

int			ft_isnum(int c)
{
	if (('0' <= c && c <= '9'))
		return (1);
	return (0);
}

int			check_width(t_struc *struc, const char *str, int z, int y)
{
	while (y < z)
	{
		if ((ft_isnum(str[y]) == 1) && str[y] != 0)
		{
			struc->width->number = ft_atoi((char *)str + y);
			return (1);
		}
		y++;
	}
	return (0);
}

int			check_precision(t_struc *struc, const char *str, int z, int y)
{
	while (y < z)
	{
		if (str[y] == '.')
		{
			struc->precision->number = ft_atoi((char *)str + y + 1);
			return (1);
		}
		y++;
	}
	return (0);
}

int			check_lenght(t_struc *struc, const char *str, int z, int y)
{
	while (y < z)
	{
		if (str[y] == 'h')
		{
			struc->lenght->h = 1;
			return (1);
		}
		if (str[y] == 'h' && str[y + 1] == 'h')
		{
			struc->lenght->hh = 1;
			return (1);
		}
		if (str[y] == 'l')
		{
			struc->lenght->l = 1;
			return (1);
		}
		if (str[y] == 'l' && str[y + 1] == 'l')
		{
			struc->lenght->ll = 1;
			return (1);
		}
		if (str[y] == 'j')
		{
			struc->lenght->j = 1;
			return (1);
		}
		if (str[y] == 'z')
		{
			struc->lenght->z = 1;
			return (1);
		}
		y++;
	}
	return (0);
}

int			width(t_struc *struc, char **buf, int len, int len_2)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * len)))
		return (0);
	if (struc->flag->zero == 1)
		tmp = ft_memset(tmp, '0', len);
	else
		tmp = ft_memset(tmp, ' ', len);
	if (len > len_2)
	{
		if (struc->flag->tiret == 1)
		{
			*buf = ft_strcat(*buf, tmp);
			struc->flag->tiret = 0;
		}
		else
		{
		}
	}
	struc->width->number = 0;
	return (len - len_2);
}

int			write_buf(t_struc *struc, char **buf, int z, va_list ap)
{
	int		x;
	int		tmp_int_s;
	char	*tmp_char_s;
	char	*tmp;
	char	*tmp_buf;

	x = 0;
	tmp = NULL;
	if ((tmp = (char *)malloc(sizeof(char) * 10)) == NULL)
		return (0);
	ft_putnbr(struc->width->number);
	ft_putstr("\n");
	if (struc->specifier->pourcent == 1)
	{
		struc->specifier->pourcent = 0;
		*buf = ft_strcat(*buf, "%");
		width(struc, buf, struc->width->number, 1);
		z++;
		return (z);
	}
	if (struc->specifier->o == 1)
	{
		struc->specifier->o = 0;
		*buf = ft_strjoin(*buf, ft_unsigned_itoa_base(va_arg(ap,
						unsigned int), 8));
		z++;
		return (z);
	}
	if (struc->specifier->om == 1)
	{
		struc->specifier->om = 0;
		*buf = ft_strjoin(*buf, ft_unsigned_long_itoa_base(va_arg(ap,
						unsigned long), 8));
		z++;
		return (z);
	}
	if (struc->specifier->c == 1)
	{
		struc->specifier->c = 0;
		tmp[0] = (unsigned char)va_arg(ap, int);
		*buf = ft_strcat(*buf, tmp);
		z++;
		return (z);
	}
	if (struc->specifier->x == 1)
	{
		struc->specifier->x = 0;
		*buf = ft_strjoin(*buf, ft_unsigned_itoa_base(va_arg(ap,
						unsigned int), 16));
		z++;
		return (z);
	}
	if (struc->specifier->xm == 1)
	{
		struc->specifier->xm = 0;
		*buf = ft_strjoin(*buf, ft_unsigned_itoa_base_m(va_arg(ap,
						unsigned int), 16));
		z++;
		return (z);
	}
	if (struc->specifier->d == 1 || struc->specifier->i == 1)
	{
		tmp_int_s = va_arg(ap, int);
		if (struc->flag->plus == 1)
			if (tmp_int_s > 0)
				tmp[0] = '+';
		z++;
		tmp = ft_strjoin(tmp, ft_itoa(tmp_int_s));
		struc->specifier->i = 0;
		struc->specifier->d = 0;
		*buf = ft_strcat(*buf, tmp);
		return (z);
	}
	if (struc->specifier->u == 1)
	{
		struc->specifier->u = 0;
		*buf = ft_strjoin(*buf, ft_unsigned_itoa(va_arg(ap, unsigned int)));
		z++;
		return (z);
	}
	if (struc->specifier->s == 1)
	{
		tmp_char_s = va_arg(ap, char *);
		z++;
		tmp = ft_strjoin(tmp, tmp_char_s);
		struc->specifier->s = 0;
		*buf = ft_strjoin(*buf, tmp);
		return (z);
	}
	if (struc->specifier->p == 1)
	{
		struc->specifier->p = 0;
		*buf = ft_strjoin(*buf, ft_strjoin("0x", ft_long_itoa_base(
						(long)va_arg(ap, void *), 16)));
		z++;
		return (z);
	}
	return (z);
}

/*
** check les flags { - | + | (space) | # | 0 }
** puis les width { (number) | * }
** ensuit la precision qui commense par un '.' suivit par { (number) | * }
** et pour finir la lenght { h | l | ll }
** aprait on regarde le specifier { s | S | p | d | D | i | o | O | u | U
** x | X | c | C } et si le specifier et un nouveau '%' afficher '%';
*/

char		*verif_line(int z, const char *str, char *buf, va_list ap)
{
	int		y;
	int		x;
	char	*tmp;
	t_struc	*struc;

	y = 0;
	x = 0;
	struc = ft_malloc_struct();
	while (str[z] != '\0')
	{
		tmp = ft_strdup(buf);
		if (str[z] == '%')
		{
			y = z + 1;
			if ((z = check_specifier(struc, str, z + 1)) == 0)
				return (NULL);
			check_flag(struc, str, z, y);
			check_width(struc, str, z, y);
			check_precision(struc, str, z, y);
			check_lenght(struc, str, z, y);
			z = write_buf(struc, &buf, z, ap);
			x = ft_strlen(buf);
		}
		else
			buf[x++] = str[z++];
	}
	return (buf);
}

void		test(const char *str, ...)
{
	va_list	ap;
	char	*buf;

	va_start(ap, str);
	if ((buf = ft_strnew(ft_strlen(str))) == NULL)
		return ;
	buf = ft_memset(buf, ft_strlen(str), 0);
	if ((buf = verif_line(0, str, buf, ap)) == NULL)
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
	printf(argv[1], 'o', ft_atoi(argv[2]), argv[3]);
	printf("\n");
	ft_putstr("ft_printf: ");
	test((const char *)argv[1], 'o', ft_atoi(argv[2]), argv[3]);
	return (0);
}
