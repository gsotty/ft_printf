/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 12:57:47 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/22 14:15:32 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_remalloc(char *dest, int len_f)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * len_f)))
		return (NULL);
	tmp = ft_memcpy(dest, tmp, len_f);
	free(dest);
	if (!(dest = (char *)malloc(sizeof(char) * len_f)))
		return (NULL);
	tmp = ft_memcpy(dest, tmp, len_f);
	free(tmp);
	return (dest);
}
