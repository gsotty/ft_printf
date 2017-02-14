/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:08:14 by tapperce          #+#    #+#             */
/*   Updated: 2017/02/09 10:54:31 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = n - 1;
	if (src < dest)
		while ((int)j >= 0)
		{
			((char*)dest)[j] = ((char*)src)[j];
			j--;
		}
	else
		while (i < n)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i++;
		}
	return (dest);
}
