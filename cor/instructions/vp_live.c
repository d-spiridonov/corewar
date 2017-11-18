/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:39:44 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/24 13:04:58 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	search_chmp(t_skrr *skrr, int value, t_proc *process)
{
	t_chmp *chmp_tmp;

	chmp_tmp = skrr->chmp;
	while (chmp_tmp)
	{
		if (chmp_tmp->id == value)
		{
			chmp_tmp->last_live = g_cycles;
			chmp_tmp->live_count += 1;
			process->live_color = 1;
			return ;
		}
		chmp_tmp = chmp_tmp->next;
	}
}

int		live_instr(t_skrr *skrr, t_proc *process)
{
	int value;

	process->sop = 0;
	if (process->waiting_cycles != g_tab[skrr->op].cycles)
		return (0);
	process->sop = -1;
	process->waiting_cycles = 0;
	process->tmp_pc = (process->pc + 1 + MEM_SIZE) % MEM_SIZE;
	value = dir_param(skrr, process, g_tab[skrr->op].dir_size);
	search_chmp(skrr, value, process);
	skrr->nbr_live += 1;
	process->live_proc = 1;
	skrr->chmp->offset = DIR_SIZE + 2;
	process->live_pc = process->pc;
	process->pc = (process->pc + skrr->chmp->offset + 1 + MEM_SIZE) % MEM_SIZE;
	process->tmp_pc = process->pc;
	return (1);
}
