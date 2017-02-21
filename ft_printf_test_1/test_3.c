/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:38:39 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/21 14:32:05 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("% h\n");
	ft_printf("%Z\n");
	ft_printf("%05%\n");
	ft_printf("%-05%\n");
	ft_printf("%\n");
	ft_printf("% \n");
	ft_printf("% hZ\n");
	ft_printf("% hZ%\n");
	ft_printf("% 10Z\n", "test");
	ft_printf("% Z \n", "test");
	ft_printf("% Z%s\n", "test");
	ft_printf("%000   %\n", "test");
	ft_printf("%%%\n", "test");
	ft_printf("%%   %\n", "test");
}
