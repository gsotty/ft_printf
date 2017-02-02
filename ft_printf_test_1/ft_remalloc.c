/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 12:57:47 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/25 15:10:50 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_remalloc(char *dest, int len_f)
{
	int		x;
	char	*tmp;

	x = ft_strlen(dest);
	if (!(tmp = (char *)malloc(sizeof(char) * len_f)))
		return (NULL);
	tmp = ft_memset(tmp, len_f, 0);
	tmp = ft_memcpy(tmp, dest, x);
	if (!(dest = (char *)malloc(sizeof(char) * len_f)))
		return (NULL);
	dest = ft_memset(dest, len_f, 0);
	dest = ft_memcpy(dest, tmp, ft_strlen(tmp));
	free(tmp);
	return (dest);
}
