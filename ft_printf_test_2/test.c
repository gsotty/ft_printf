/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:04:54 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/14 09:33:13 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <stdio.h>

int		main(void)
{
	printf("Ptest %%d\n");
	printf("%d\n", 42);
	printf("%-d\n", 42);
	printf("%+d\n", 42);
	printf("% d\n", 42);
	printf("%0d\n", 42);
	printf("%d\n", -42);
	printf("%10d\n", 42);
	printf("%-10d\n", 42);
	printf("%+10d\n", 42);
	printf("% 10d\n", 42);
	printf("%010d\n", 42);
	printf("%10d\n", -42);
	printf("%10.8d\n", 42);
	printf("%-10.8d\n", 42);
	printf("%+10.8d\n", 42);
	printf("% 10.8d\n", 42);
	printf("%010.8d\n", 42);
	printf("%10.8d\n", -42);
	printf("%5.8d\n", 42);
	printf("%-5.8d\n", 42);
	printf("%+5.8d\n", 42);
	printf("% 5.8d\n", 42);
	printf("%05.8d\n", 42);
	printf("%5.8d\n", -42);
	printf("%05.8d\n", 42);
	printf("%-05.8d\n", 42);
	printf("%+05.8d\n", 42);
	printf("% 05.8d\n", 42);
	printf("%005.8d\n", 42);
	printf("%05.8d\n", -42);
	ft_printf("Ftest %%d\n");
	ft_printf("%d\n", 42);
	ft_printf("%-d\n", 42);
	ft_printf("%+d\n", 42);
	ft_printf("% d\n", 42);
	ft_printf("%0d\n", 42);
	ft_printf("%d\n", -42);
	ft_printf("%10d\n", 42);
	ft_printf("%-10d\n", 42);
	ft_printf("%+10d\n", 42);
	ft_printf("% 10d\n", 42);
	ft_printf("%010d\n", 42);
	ft_printf("%10d\n", -42);
	ft_printf("%10.8d\n", 42);
	ft_printf("%-10.8d\n", 42);
	ft_printf("%+10.8d\n", 42);
	ft_printf("% 10.8d\n", 42);
	ft_printf("%010.8d\n", 42);
	ft_printf("%10.8d\n", -42);
	ft_printf("%5.8d\n", 42);
	ft_printf("%-5.8d\n", 42);
	ft_printf("%+5.8d\n", 42);
	ft_printf("% 5.8d\n", 42);
	ft_printf("%05.8d\n", 42);
	ft_printf("%5.8d\n", -42);
/*
*/
/*
	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%O\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);
*/	return (0);
}
