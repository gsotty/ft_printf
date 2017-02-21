/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:04:54 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/21 10:19:12 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

static void	test_3(void)
{
	printf("p%#x\n", 42);
	ft_printf("f%#x\n", 42);
	printf("p%#O\n", 42);
	ft_printf("f%#O\n", 42);
	printf("p%#o\n", 42);
	ft_printf("f%#o\n", 42);
	printf("p{%030x}\n", 0xFFFF);
	ft_printf("f{%030x}\n", 0xFFFF);
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
}

static void	test_2(void)
{
	printf("%%", "test");
	ft_printf("%%", "test");
	printf("% Z%s", "test");
	ft_printf("% Z%s", "test");
	printf("%05%");
	ft_printf("%05%");
	printf("% hZ");
	ft_printf("% hZ");
	printf("%Z");
	ft_printf("%Z");
	printf("% h");
	ft_printf("% h");
	printf("% ");
	ft_printf("% ");
	printf("%");
	ft_printf("%");
	printf("p%p\n", 42);
	ft_printf("f%p\n", 42);
	printf("p%#X\n", 42);
	ft_printf("f%#X\n", 42);
	test_3();
}

static void	test_1(void)
{
	printf("% Z");
	ft_printf("% h");
	printf("p{%05.S}\n", 0);
	ft_printf("f{%05.S}\n", 0);
	printf("p%C%C\n", '4', '2');
	ft_printf("f%C%C\n", '4', '2');
	printf("p%lc, %lc\n", L'暖', L'ح');
	ft_printf("f%lc, %lc\n", L'暖', L'ح');
	printf("p%.4ls\n", L"我是一只猫。");
	ft_printf("f%.4S\n", L"我是一只猫。");
	printf("p%15.4ls\n", L"我是一只猫。");
	ft_printf("f%15.4S\n", L"我是一只猫。");
	printf("p{%03c}\n", 0);
	ft_printf("f{%03c}\n", 0);
	printf("p{%-15Z}\n", 123);
	ft_printf("f{%-15Z}\n", 123);
	printf("p%#o\n", 42);
	ft_printf("f%#o\n", 42);
	printf("p.%%.%%.%%.%%.%%.%%.%%.%%.\n");
	ft_printf("f.%%.%%.%%.%%.%%.%%.%%.%%.\n");
	test_2();
}

static void	test_0(void)
{
	printf("%ll#x", 9223372036854775807);
	ft_printf("%ll#x", 9223372036854775807);
	ft_printf("%zhd\n", 4294967296);
	ft_printf("%jzd\n", 9223372036854775807);
	ft_printf("%jhd\n", 9223372036854775807);
	ft_printf("%lhl\n", 9223372036854775807);
	ft_printf("%lhlz\n", 9223372036854775807);
	ft_printf("%zj\n", 9223372036854775807);
	ft_printf("%lhh\n", 2147483647);
	ft_printf("%hhld\n", 128);
	printf("@main_printf: %####0000 33..1..#00d\n", 256);
	ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
	printf("@main_printf: %####0000 33..1d\n", 256);
	ft_printf("@main_ftprintf: %####0000 33..1d\n", 256);
	printf("@main_printf: %###-#0000 33...12..#0+0d\n", 256);
	ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
	printf("% ");
	ft_printf("% ");
	printf("% h");
	ft_printf("% Z");
	test_1();
}

int			main(void)
{
	setlocale(LC_ALL, "");
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
	test_0();
	return (0);
}
