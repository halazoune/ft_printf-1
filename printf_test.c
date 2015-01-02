/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 18:39:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/02 16:21:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

#define TEST(s, ...)	printf("\033[36m%s :\033[0m ", s);fflush(stdout);printf(" \033[36m;\033[0m %d\n", _printf(s, ##__VA_ARGS__));fflush(stdout);

static void		test(int (*_printf)(const char *format, ...))
{
	TEST("lol%s", "Hello");
	TEST("%#; ;+;-';0;s", "---- %% ----");
	TEST("%%");
	TEST("%30%");
	TEST("% -30%.");
	TEST("%.0%");
	TEST("%0-5%");
	TEST("%0-5");
	TEST("%0-5..%");
	TEST("ll# 2.3hd");
	TEST("%#; ;+;-';0;s", "--- s/S ---");
	TEST("%s", "test test test");
	TEST("%s", "");
	TEST("%.8s", "");
	TEST("%.8s", "test test test");
	TEST("%.0s", "test test test");
	TEST("%.-0s", "test test test");
	TEST("%.-1s", "test lol");
	TEST("%.-5s", "test lol");
	TEST("%+.-5s", "test lol");
	TEST("%.0s", "");
	TEST("%0-15s", "test");
	TEST("%15.5s", "test test");
	TEST("%-15.5s", "test test");
	TEST("|%-^15.5s|", "test test");
	TEST("%#; ;+;-';0;s", "-- d/D/i --");
	TEST("%-5.2d", 80);
	TEST("-20 = %i;", -20);
	TEST("20 = %i;", 20);
	TEST("%D", 0);
	TEST("%i", -2);
	TEST("%+D", 9984465411154);
	TEST("%+'D", 9984465411154);
	TEST("%-22.5i", 9984465411154);
	TEST("%i", -2147483648);
	TEST("%'i", -2147483648);
	TEST("%010i", 5);
	TEST("% i", 0);
	TEST("%+i", 0);
	TEST("% +i", 845);
	TEST("%.-1i", 845);
	TEST("%+ i", 7522);
	TEST("% i", 7522);
	TEST("%*i", 10, 5);
	TEST("%'*i", 10, 5);
	TEST("%'*i", -10, 5);
	TEST("%hhi", 5);
	TEST("%+hhi", 5987);
	TEST("%'+'hhi", 8522);
	TEST("%#; ;+;-';0;s", "--- o/O ---");
	TEST("%o", 5587745);
	TEST("%5.4llo", 99887744114);
	TEST("%5.4O", 99887744114);
	TEST("%O", -885);
	TEST("%#+O", -15008);
	TEST("%#-5O", 8);
	TEST("%#O", 0);
	TEST("%#+O", 0);
	TEST("%#; ;+;-';0;s", "--- u/U ---");
	TEST("%u", 5588);
	TEST("%u", -5588);
	TEST("% u", 0);
	TEST("%+u", 0);
	TEST(">>%u<<", 3000000000);
	TEST("%-50us", 999999999);
	TEST("%#Us", 28789323991);
	TEST("%+uus", -68416454563);
	TEST("%#; ;+;-';0;s", "--- x/X ---");
	TEST("%#; ;+;-';0;s", "--- c/C ---");
	TEST("%c", 'c');
	TEST("%.-1c", 'c');
	TEST("%.--1c", 'c');
	TEST("%c %c", 'F', 'Q');
	TEST("%C %C", 'f', 'q');
/*
	TEST("%c %C", '\500', '\250');
	TEST("%C %c", '\500', '\250');
*/
	TEST("%#; ;+;-';0;s", "---- n ----");
	int			n;
	TEST("123456789%n", &n);
	TEST("------> %d", n);
	TEST("% +.-5n", &n);
	TEST("------> %d", n);
	TEST(">> %n <<", &n);
	TEST("------> %d", n);
	TEST("%n", &n);
	TEST("------> %d", n);
	void		*p = 0x7fff5015badc;
	TEST("%#; ;+;-';0;s", "---- p ----");
	TEST("%p", p);
	TEST("NULL = %p", NULL);
	TEST("ll %p", (unsigned long long int)p);
	TEST("ll %p", ((unsigned long long int)p) * 10);
	TEST("%#; ;+;-';0;s", "--- e/E ---");
	TEST("%e", 5.9987445633);
	TEST("%.*e", 12, 5.9987445633);
	TEST("%.*e", 12, 5.3);
	TEST("%.0e", 5.83);
	TEST("%.*e", 12, (double)6871435146546545);
	TEST("%.*Le", 15, (long double)68714351465445.99);
	TEST("%.*E", 15, (long double)68714351465445);
	TEST("%#-*.*Le", 29, 12, (long double)68715146546545);
	TEST("% +.*Le", 12, (long double)68715146546545);
	TEST("%+ .*Le", 12, (long double)68715146546545);
	TEST("% .*Le", 12, (long double)68715146546545);
	TEST("% .*e", 12, NAN);
	TEST("% E", (double)68715146546545);
	TEST("|%- +*.*Le|", 30, 21, (long double)2.552997774654998741135);
	TEST("%#; ;+;-';0;s", "--- f/F ---");
	TEST("%F", 5.9987445633);
	TEST("%.*f", 12, 5.9987445633);
	TEST("%.0f", 5.83);
	TEST("%.*f", 12, 5.3);
	TEST("%.*f", 12, NAN);
	TEST("%.*f", 12, (long double)6871435146546545);
	TEST("%.*Lf", 12, (long double)68714351465445);
	TEST("%.-5Lf", (long double)68714351465445.99);
	TEST("%-8.-5Lf", (long double)68714351465445);
	TEST("%#-*.*LF", 29, 12, (long double)68715146546545);
	TEST("% +.*Lf", 12, (long double)68715146546545);
	TEST("% f", (double)68715146546545);
	TEST("|%- +*.*F|", 30, 21, (long double)2.552997774654998741135);
	TEST("%#; ;+;-';0;s", "--- b/B ---");
	TEST("%#; ;+;-';0;s", "--- r/R ---");
	TEST("%#; ;+;-';0;s", "--- g/G ---");
	TEST("%.0g", 5.83);
	TEST("%.*g", 12, 5.3);
	TEST("%.*g", 12, (long double)6871435146546545);
	TEST("%.*Lg", 12, (long double)5.9987445633);
	TEST("%+ .*LG", 12, (long double)5.9987445633);
	TEST("% .*LG", 12, (long double)5.9987445633);
	TEST("% .*G", 12, NAN);
	TEST("% G", (double)68715146546545.2);
}

int				main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("\033[34mTest: %s\033[0m\n", "printf");
		test(printf);
	}
	else
	{
		printf("\033[34mTest: %s\033[0m\n", "ft_printf");
		test(ft_printf);
	}
	(void)argv;
	return (0);
}
