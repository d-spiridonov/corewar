/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:38:18 by vpoltave          #+#    #+#             */
/*   Updated: 2017/10/25 11:17:13 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		lld_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int				address;
	int				reg;

	reg = 0;
	if (!fuck_norm(skrr, process, 12))
		return (0);
	if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
		exit(0);
	if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
		return (0);
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	(q[0] == T_IND) ? address = ind_param(skrr, process, 4) : 0;
	(q[0] == T_DIR) ? address = dir_param(skrr, process, 0) : 0;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[1] == T_REG)
		if (!(reg = reg_param(skrr, process, 2)) && (g_err))
		{
			free(q);
			return (g_err = 0);
		}
	fuck_norm_2(skrr, process, reg, address);
	free(q);
	return (1);
}
