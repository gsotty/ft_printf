/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:09:34 by tapperce          #+#    #+#             */
/*   Updated: 2016/11/23 13:55:49 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*str1;
	char		*str2;

	i = 0;
	str1 = (char*)src;
	str2 = (char*)dest;
	while (i < n)
	{
		str2[i] = str1[i];
		if (str1[i] == c)
			return (str2 + i + 1);
		i++;
	}
	return (NULL);
}
