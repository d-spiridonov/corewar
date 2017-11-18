/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:31:42 by vpoltave          #+#    #+#             */
/*   Updated: 2017/10/24 21:30:30 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		entry_point(t_skrr *skrr, t_chmp *chmp)
{
	(skrr->flag_v == 0) ? print_info(skrr->chmp) : 0;
	while (skrr->cycle_to_die > 0)
	{
		(g_cycles == 0) ? process_first_pos(skrr->chmp, skrr->process) : 0;
		skrr->flag_v ? visualize(skrr) : 0;
		g_cycles++;
		g_ctd++;
		change_process(skrr, chmp, &skrr->process);
		((int)g_cycles - 1 == skrr->flag_dump) ? dump_print(skrr) : 0;
		if (g_ctd == skrr->cycle_to_die)
			init_lives(skrr);
	}
	winner(chmp, skrr, skrr->chmp->last_live, skrr->chmp->id);
	return (1);
}

int		change_process(t_skrr *skrr, t_chmp *chmp, t_proc **process)
{
	t_proc *proc_tmp;

	proc_tmp = *process;
	while (proc_tmp)
	{
		skrr->op = -1;
		chmp->offset = 0;
		which_instr(skrr, &proc_tmp);
		proc_tmp = proc_tmp->next;
	}
	return (1);
}

int		process_first_pos(t_chmp *chmp, t_proc *proc)
{
	t_proc *proc_tmp;
	t_chmp *chmp_tmp;

	proc_tmp = proc;
	chmp_tmp = chmp;
	if (!chmp_tmp || !proc_tmp)
		exit(0);
	while (chmp_tmp && proc_tmp)
	{
		proc_tmp->pc = chmp_tmp->player_pos;
		proc_tmp = proc_tmp->next;
		chmp_tmp = chmp_tmp->next;
	}
	return (1);
}

void	which_instr(t_skrr *skrr, t_proc **process)
{
	while (++skrr->op < 16)
		if (skrr->map[(*process)->pc] == g_tab[skrr->op].opcode ||
				(*process)->sop != -1)
		{
			(*process)->waiting_cycles++;
			((*process)->sop != -1) ? skrr->op = (*process)->sop : 0;
			(skrr->op == 0) ? live_instr(skrr, *process) : 0;
			(skrr->op == 1) ? ld_instr(skrr, *process) : 0;
			(skrr->op == 2) ? st_instr(skrr, *process) : 0;
			(skrr->op == 3) ? add_instr(skrr, *process) : 0;
			(skrr->op == 4) ? sub_instr(skrr, *process) : 0;
			(skrr->op == 5) ? and_instr(skrr, *process) : 0;
			(skrr->op == 6) ? or_instr(skrr, *process) : 0;
			(skrr->op == 7) ? xor_instr(skrr, *process) : 0;
			(skrr->op == 8) ? zjmp_instr(skrr, *process) : 0;
			(skrr->op == 9) ? ldi_instr(skrr, *process) : 0;
			(skrr->op == 10) ? sti_instr(skrr, *process) : 0;
			(skrr->op == 11) ? fork_instr(skrr, process) : 0;
			(skrr->op == 12) ? lld_instr(skrr, *process) : 0;
			(skrr->op == 13) ? lldi_instr(skrr, *process) : 0;
			(skrr->op == 14) ? lfork_instr(skrr, process) : 0;
			(skrr->op == 15) ? aff_instr(skrr, *process) : 0;
			return ;
		}
	(*process)->pc = ((*process)->pc + 1 + MEM_SIZE) % MEM_SIZE;
}

int		init_lives(t_skrr *skrr)
{
	t_chmp	*champ_tmp;

	champ_tmp = skrr->chmp;
	while (champ_tmp)
	{
		champ_tmp->live_count = 0;
		champ_tmp = champ_tmp->next;
	}
	kill_processes(&skrr->process, skrr);
	if (skrr->process == NULL)
		winner(skrr->chmp, skrr, skrr->chmp->last_live, skrr->chmp->id);
	if (skrr->nbr_live >= NBR_LIVE && (skrr->max_checks = MAX_CHECKS))
		skrr->cycle_to_die -= CYCLE_DELTA;
	else
	{
		skrr->max_checks--;
		if (skrr->max_checks == 0 && (skrr->max_checks = MAX_CHECKS))
			skrr->cycle_to_die -= CYCLE_DELTA;
	}
	skrr->nbr_live = 0;
	g_ctd = 0;
	return (1);
}
