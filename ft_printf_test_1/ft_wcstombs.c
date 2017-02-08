/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:57:20 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/31 17:08:53 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_wcstombs_1(char *dest, const wchar_t *src,
		size_t y, size_t x)
{
	size_t	mask;

	mask = 1;
	mask = ((mask << 8) - 1);
	dest[y] = (char)(mask & (size_t)src[x]);
	y++;
	return (y);
}

static size_t	ft_wcstombs_2(char *dest, const wchar_t *src,
		size_t y, size_t x)
{
	size_t	mask;

	mask = 1;
	mask = src[x] >> 6;
	dest[y] = (char)(mask | 192);
	y++;
	mask = ((1 << 6) - 1) & src[x];
	dest[y] = (char)(mask | 128);
	y++;
	return (y);
}

static size_t	ft_wcstombs_3(char *dest, const wchar_t *src,
		size_t y, size_t x)
{
	size_t	mask;

	mask = 1;
	mask = src[x] >> 12;
	dest[y] = (char)(mask | 224);
	y++;
	mask = ((1 << 12) - 1) & src[x];
	mask = mask >> 6;
	dest[y] = (char)(mask | 128);
	y++;
	mask = ((1 << 6) - 1) & src[x];
	dest[y] = (char)(mask | 128);
	y++;
	return (y);
}

static size_t	ft_wcstombs_4(char *dest, const wchar_t *src,
		size_t y, size_t x)
{
	size_t	mask;

	mask = 1;
	mask = src[x] >> 18;
	dest[y] = (char)(mask | 240);
	y++;
	mask = ((1 << 18) - 1) & src[x];
	mask = mask >> 12;
	dest[y] = (char)(mask | 128);
	y++;
	mask = ((1 << 12) - 1) & src[x];
	mask = mask >> 6;
	dest[y] = (char)(mask | 128);
	y++;
	mask = ((1 << 6) - 1) & src[x];
	dest[y] = (char)(mask | 128);
	y++;
	return (y);
}

size_t			ft_wcstombs(char *dest, const wchar_t *src, size_t n)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (src[x] != '\0' && y < n)
	{
		if ((int)src[x] <= 127)
			y = ft_wcstombs_1(dest, src, y, x);
		else if ((int)src[x] >= 128 && (int)src[x] <= 2047)
			y = ft_wcstombs_2(dest, src, y, x);
		else if ((int)src[x] >= 2048 && (int)src[x] <= 65535)
			y = ft_wcstombs_3(dest, src, y, x);
		else if ((int)src[x] >= 65536 && (int)src[x] <= 1114111)
			y = ft_wcstombs_4(dest, src, y, x);
		x++;
	}
	return (0);
}
