/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_virtual_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:12:55 by vpoltave          #+#    #+#             */
/*   Updated: 2017/08/08 15:42:25 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

unsigned long	g_cycles;
int				g_ctd;
int				g_err;

int				main(int argc, char **argv)
{
	t_skrr	skrr;

	init(&skrr);
	(argc == 1) ? usage_e() : 0;
	parsing_arg(&skrr, argv, argc);
	if (skrr.flag_v == 1)
		visualize_init(&skrr);
	entry_point(&skrr, skrr.chmp);
	close(skrr.fd) < 0 ? exit(0) : 0;
	return (0);
}
