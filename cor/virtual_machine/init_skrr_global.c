/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skrr_&_global.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:48:46 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/24 21:25:42 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	init(t_skrr *skrr)
{
	skrr->fd = 0;
	skrr->i = 0;
	skrr->j = 0;
	skrr->n = 0;
	skrr->op = 0;
	skrr->shift = 0;
	skrr->init_id = 1;
	skrr->flag_n = NULL;
	skrr->cnt_n = 0;
	skrr->flag_v = 0;
	skrr->flag_dump = -1;
	skrr->flag_a = 0;
	skrr->max_player = 0;
	skrr->max_checks = MAX_CHECKS;
	skrr->cycle_to_die = CYCLE_TO_DIE;
	skrr->process_count = 0;
	skrr->nbr_live = 0;
	g_cycles = 0;
	g_ctd = 0;
	g_err = 0;
	skrr->chmp = NULL;
	skrr->process = NULL;
}

void	init_flag(t_skrr *skrr)
{
	if (skrr->flag_v == 1)
	{
		skrr->flag_a = 0;
		skrr->flag_dump = -1;
	}
}

int		fuck_norm(t_skrr *skrr, t_proc *process, int sop)
{
	process->sop = sop;
	if (process->waiting_cycles != g_tab[skrr->op].cycles)
		return (0);
	process->sop = -1;
	process->waiting_cycles = 0;
	return (1);
}

void	fuck_norm_2(t_skrr *skrr, t_proc *process, int reg, int address)
{
	process->registry[reg] = (unsigned int)address;
	process->carry = (address == 0) ? 1 : 0;
	process->pc = (process->pc + skrr->chmp->offset + 2 + MEM_SIZE) % MEM_SIZE;
	process->tmp_pc = process->pc;
}
