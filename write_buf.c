/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 09:49:55 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/08 14:09:14 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_buf_4(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	if (struc->specifier.c == 1)
	{
		write_c(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.cm == 1)
	{
		write_cm(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
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

static int	write_buf_3(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	if (struc->specifier.um == 1)
	{
		write_um(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
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
	if (write_buf_4(struc, buf, len, ap) == 1)
		return (1);
	return (0);
}

static int	write_buf_2(t_struc *struc, char **buf, t_len *len, va_list ap)
{
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
	if (write_buf_3(struc, buf, len, ap) == 1)
		return (1);
	return (0);
}

static int	write_buf_1(t_struc *struc, char **buf, t_len *len, va_list ap)
{
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
	if (write_buf_2(struc, buf, len, ap) == 1)
		return (1);
	return (0);
}

int			write_buf(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char*tmp;

	tmp = NULL;
	if (struc->specifier.s == 1)
	{
		write_s(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.sm == 1)
	{
		write_sm(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (struc->specifier.p == 1)
	{
		write_p(struc, buf, len, ap);
		len->pos_buf = ft_strlen(*buf);
		return (1);
	}
	if (write_buf_1(struc, buf, len, ap) == 1)
		return (1);
	return (0);
}
