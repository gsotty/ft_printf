/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:43:33 by tapperce          #+#    #+#             */
/*   Updated: 2016/11/24 18:40:43 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	len = ft_strlen((char*)lil);
	if (!len)
		return ((char*)big);
	while (big[i] && i < n)
	{
		j = 0;
		while (big[i + j] == lil[j] && big[i + j] && lil[j] && i + j < n)
			j++;
		if (j == len)
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}
