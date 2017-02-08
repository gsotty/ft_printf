/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:23:56 by tapperce          #+#    #+#             */
/*   Updated: 2016/11/28 15:38:25 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char*)s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char*)s + i);
		i--;
	}
	return (NULL);
}
