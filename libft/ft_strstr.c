/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:44:08 by tapperce          #+#    #+#             */
/*   Updated: 2016/11/28 16:26:09 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return ((char*)haystack);
	if (*haystack == '\0')
		return (NULL);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, ft_strlen((char*)needle)) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
