/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:39:31 by vpoltave          #+#    #+#             */
/*   Updated: 2017/10/25 11:33:32 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		aff_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char print_it;

	process->sop = 15;
	if (process->waiting_cycles != g_tab[skrr->op].cycles)
		return (0);
	process->sop = -1;
	process->tmp_pc = (process->pc + 2 + MEM_SIZE) % MEM_SIZE;
	process->waiting_cycles = 0;
	if (!(print_it = (unsigned char)reg_param(skrr, process, 1)) && (g_err))
		return (g_err = 0);
	skrr->flag_a == 1 ? ft_printf("Aff: %c\n", (print_it % 256)) : 0;
	process->pc = (process->pc + 3 + MEM_SIZE) % MEM_SIZE;
	return (1);
}
