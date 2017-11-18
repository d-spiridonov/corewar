/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_main_asm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:36:27 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 19:48:19 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

t_file	*g_file;
t_asm	g_asm;

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	lets_get_null();
	(argc == 1) ? print_usage(0, "none") : 0;
	if (argc > 1)
		while (++i <= (argc - 1))
			(argv[i][0] == '-' && argv[i][1] == 'a' && argv[i][2] == '\0') ?
					g_asm.a = 1 : 0;
	i = 1;
	if (argc > 1)
	{
		while (i <= (argc - 1))
		{
			lets_get_null_for_file();
			if (name_s(argv[i], argv[i]) && g_validation(argv[i], NULL))
				g_asm.a == 1 ? print_with_a(g_file) : create_file(g_file);
			i++;
		}
	}
	return (0);
}
