/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 08:45:29 by tapperce          #+#    #+#             */
/*   Updated: 2016/11/24 18:17:17 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char*)s;
	while (i < n)
	{
		if (((unsigned const char *)str)[i] == (unsigned char)c)
			return ((void*)str + i);
		i++;
	}
	return (NULL);
}
