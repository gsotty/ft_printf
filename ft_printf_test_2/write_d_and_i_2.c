/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d_and_i_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 09:10:56 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/14 09:31:32 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_d_and_i_2(t_struc *struc, char **buf, t_len *len, va_list ap)
{
	char	*tmp;

	tmp = modif_longeur_d_and_i(struc, ap);
	
}
