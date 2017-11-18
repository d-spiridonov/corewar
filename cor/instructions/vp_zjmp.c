/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:20 by vpoltave          #+#    #+#             */
/*   Updated: 2017/10/24 13:01:41 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		zjmp_instr(t_skrr *skrr, t_proc *process)
{
	int address;

	process->sop = 8;
	if ((process->carry) &&
			(process->waiting_cycles == g_tab[skrr->op].cycles))
	{
		process->sop = -1;
		process->tmp_pc = (process->pc + 1 + MEM_SIZE) % MEM_SIZE;
		address = dir_param(skrr, process, g_tab[skrr->op].dir_size);
		address = (process->pc + (address % IDX_MOD));
		process->pc = (address + MEM_SIZE) % MEM_SIZE;
		process->tmp_pc = process->pc;
		process->waiting_cycles = 0;
	}
	else if ((process->carry == 0) &&
			(process->waiting_cycles == g_tab[skrr->op].cycles))
	{
		process->sop = -1;
		process->pc = (process->pc + DIR_SIZE + 1 + MEM_SIZE) % MEM_SIZE;
		process->tmp_pc = process->pc;
		process->waiting_cycles = 0;
	}
	return (1);
}
