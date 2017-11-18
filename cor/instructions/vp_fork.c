/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:59 by vpoltave          #+#    #+#             */
/*   Updated: 2017/10/24 12:56:04 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		fork_instr(t_skrr *skrr, t_proc **process)
{
	int address;
	int pc;

	(*process)->sop = 11;
	if ((*process)->waiting_cycles != g_tab[skrr->op].cycles)
		return (0);
	(*process)->sop = -1;
	(*process)->waiting_cycles = 0;
	(*process)->tmp_pc = ((*process)->pc + 1 + MEM_SIZE) % MEM_SIZE;
	address = dir_param(skrr, *process, g_tab[skrr->op].dir_size);
	address = ((*process)->pc + (address % IDX_MOD));
	pc = (address + MEM_SIZE) % MEM_SIZE;
	(*process)->pc = ((*process)->pc + 3 + MEM_SIZE) % MEM_SIZE;
	(*process)->tmp_pc = (*process)->pc;
	inheritance_proc(process, pc, skrr);
	return (1);
}
