/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 12:57:47 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/09 11:05:24 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_remalloc(char *dest, int len_d, int len_s)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * len_d)))
		return (NULL);
	tmp = ft_memset(tmp, len_d, 0);
	tmp = ft_memcpy(tmp, dest, len_s);
	if (!(dest = (char *)malloc(sizeof(char) * len_d)))
		return (NULL);
	dest = ft_memset(dest, len_d, 0);
	dest = ft_memcpy(dest, tmp, len_d);
	dest[len_s] = '\0';
	free(tmp);
	return (dest);
}
