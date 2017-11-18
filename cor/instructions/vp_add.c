/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:49:35 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/24 13:03:37 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		add_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int				address;
	int				reg;

	if (!fuck_norm(skrr, process, 3))
		return (0);
	if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
		exit(0);
	if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
		return (0);
	if (!(address = det_of_action(q, skrr, 1, process)) && (g_err))
	{
		free(q);
		return (g_err = 0);
	}
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (!(reg = reg_param(skrr, process, 2)) && (g_err))
	{
		free(q);
		return (g_err = 0);
	}
	fuck_norm_2(skrr, process, reg, address);
	free(q);
	return (1);
}
