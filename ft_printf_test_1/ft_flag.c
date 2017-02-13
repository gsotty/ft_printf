/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 09:30:28 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/13 10:10:51 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag(char *tmp, t_len *len, char *str)
{
	int		len_str;
	char	*tmp_char;

	tmp_char = NULL;
	len_str = ft_strlen(str);
	tmp_char = ft_strdup(str);
	ft_remalloc(tmp_char, len->len_tmp + len_str, len_str);
	ft_memmove(tmp_char + len_str, tmp, len->len_tmp + len_str);
//	free(tmp);
	tmp = ft_strdup(tmp_char);
	len->len_tmp += 1;
	return (tmp);
}
