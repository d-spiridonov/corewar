/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:37:38 by vpoltave          #+#    #+#             */
/*   Updated: 2017/10/24 12:57:08 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		ldi_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int				address;

	if (!fuck_norm(skrr, process, 9))
		return (0);
	if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
		exit(0);
	if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
		return (0);
	if (!(address = get_address(q, skrr, process, 0)) && (g_err))
	{
		free(q);
		return (g_err = 0);
	}
	address = (process->pc + (address % IDX_MOD));
	if (!(load_into(address, process, skrr, 2)) && (g_err))
	{
		free(q);
		return (g_err = 0);
	}
	process->pc = (process->pc + skrr->chmp->offset + 2 + MEM_SIZE) % MEM_SIZE;
	process->tmp_pc = process->pc;
	free(q);
	return (1);
}
