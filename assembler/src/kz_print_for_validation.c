/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_print_for_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:37:21 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:39:12 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		print_usage(int i, char *s)
{
	((i == 1) || (i == 2) || (i == 0)) ? 0 : ft_printf("%s:  ", usage());
	(i == 0) ? (ft_printf("Usage: ./asm [-a] <sourcefile.s>\n\t-a : Instead of "
		"creating a .cor file, outputs a stripped and annotated version "
							"of the code to the standard output\n")) : 0;
	(i == 1) ? (ft_printf("Writing output program to %s\n", s)) : 0;
	(i == 2) ? (ft_printf("Can't read source file %s\n", s)) : 0;
	(i == 3) ? (ft_printf(RED "ERROR, line [%03d]\n" RESET, g_asm.l)) : 0;
	(i == 4) ?
	(ft_printf(YEL "Lexical error at line [%03d]\n" RESET, g_asm.l)) : 0;
	(i == 5) ? (ft_printf(RED "ERROR, too much commands '%s'\n" RESET, s)) : 0;
	(i == 6) ? (ft_printf(RED "ERROR, too much commands '%s'\n" RESET, s)) : 0;
	(i == 7) ? (ft_printf(MAG "Syntax error in the "
									"string \"%s\"\n" RESET, s)) : 0;
	(i == 8) ? (ft_printf(RED "Invalid instruction at line "
										"[%03d]\n" RESET, g_asm.l)) : 0;
	(i == 9) ?
	(ft_printf(BBLU "Syntax error - unexpected end of input (Perhaps you forgot"
							" to end with a newline?)" RESET "\n")) : 0;
	(i == 10) ? (ft_printf(RED "%s\n" RESET, s)) : 0;
	(i == 11) ?
	(ft_printf(MAG "Syntax error at line [%03d]\n" RESET, g_asm.l)) : 0;
	(i == 12) ? (ft_printf(BCYN "%s" RESET "\n", s)) : 0;
	(i == 13) ? (ft_printf(MAG "Syntax error at line [%03d], no separator "
						"after instruction '%s'\n" RESET, g_asm.l, s)) : 0;
	return (0);
}

int		print_usage_0(int i, char *s)
{
	(i == 3) ? ft_printf("%s: ", s) : ft_printf("%s:  ", usage());
	(i == 0) ?
	(ft_printf(YEL "Lexical error at line [%03d]\n" RESET, g_asm.count)) : 0;
	(i == 1) ?
	(ft_printf(MAG "Syntax error at line [%03d], "
						"LABEL\n" RESET, g_asm.count)) : 0;
	(i == 2) ? (ft_printf(MAG "Syntax error. END \"(null)\"\n" RESET)) : 0;
	(i == 3) ? (ft_printf(BLU "Sorry man, "
								"I need only *.s files :(\n" RESET)) : 0;
	return (0);
}

int		print_usage_1(int i, char *s, int param, char *p)
{
	ft_printf("%s:  ", usage());
	(i == 0) ? (ft_printf(RED "Invalid parameter %d type %s for instruction "
									"%s\n" RESET, param, p, s)) : 0;
	(i == 1) ?
	(ft_printf(MAG "Syntax error, no separator after parameter %d type %s for "
						"instruction '%s'\n" RESET, param, p, s)) : 0;
	(i == 2) ?
	(ft_printf(MAG "Syntax error at token '%c' "
						"ENDLINE\n" RESET, SEPARATOR_CHAR)) : 0;
	(i == 3) ?
	(ft_printf(BMAG "Label does not exist, line [%03d], instruction <%s>"
										RESET "\n", g_asm.l, s)) : 0;
	(i == 4) ? (ft_printf(RED "Invalid parameter %d type for instruction "
									"%s\n" RESET, param, s)) : 0;
	return (0);
}
