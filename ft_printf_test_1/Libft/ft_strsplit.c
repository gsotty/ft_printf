/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:57:18 by tapperce          #+#    #+#             */
/*   Updated: 2016/11/28 16:44:38 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = -1;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(str = malloc(sizeof(char*) * ft_nb_word(s, c) + 1)))
		return (NULL);
	while (s[++i])
		if (s[i] != c)
		{
			if (!(str[k] = malloc(sizeof(char) * ft_len_word((s + i), c) + 1)))
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				str[k][j++] = s[i++];
			str[k++][j] = '\0';
			j = 0;
			i--;
		}
	str[k] = 0;
	return (str);
}
