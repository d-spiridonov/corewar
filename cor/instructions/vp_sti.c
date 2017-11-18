/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:47 by vpoltave          #+#    #+#             */
/*   Updated: 2017/10/24 12:59:39 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		sti_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int				address;

	process->sop = 10;
	if (process->waiting_cycles != g_tab[skrr->op].cycles)
		return (0);
	process->sop = -1;
	process->waiting_cycles = 0;
	if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
		exit(0);
	if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
		return (0);
	if (!from_reg(q, process, skrr, 0) && (g_err))
		return (g_err = 0);
	if (!(address = get_address(q, skrr, process, 1)) && (g_err))
	{
		free(q);
		return (g_err = 0);
	}
	address = (process->pc + (address % IDX_MOD));
	load_into(address, process, skrr, 1);
	process->pc = (process->pc + skrr->chmp->offset + 2 + MEM_SIZE) % MEM_SIZE;
	process->tmp_pc = process->pc;
	free(q);
	return (1);
}
