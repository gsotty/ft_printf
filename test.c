/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:45:05 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/08 14:11:28 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("printf =\t\"%10c is %5c string\"\n", 'A', 'a');
	ft_printf("ft_printf =\t\"%10c is %5c string\"\n", 'A', 'a');
	return (0);
}
