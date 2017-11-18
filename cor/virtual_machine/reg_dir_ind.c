/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_dir_ind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:30:59 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/10 17:31:00 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
**	flag = 1 -> get value from registry, 2 -> just get number of registry
*/

int		reg_param(t_skrr *skrr, t_proc *process, int flag)
{
	if (((skrr->map[process->tmp_pc] > REG_NUMBER) ||
			(skrr->map[process->tmp_pc] < 1)) && (g_err = 1))
	{
		process->pc =
				((process->pc + skrr->chmp->offset + 2 + MEM_SIZE) % MEM_SIZE);
		return (0);
	}
	if (flag == 1)
		return (process->registry[skrr->map[process->tmp_pc] - 1]);
	else if (flag == 2)
		return (skrr->map[process->tmp_pc] - 1);
	return (0);
}

/*
**	dir_size, if dir_size = 1 -> means DIR_SIZE = 2 bytes,
**  0 -> DIR_SIZE = 4 bytes
*/

int		dir_param(t_skrr *skrr, t_proc *process, short dir_size)
{
	int address;

	address = 0;
	if (dir_size == 1)
	{
		address = (short)two_four_bytes(&skrr->map[process->tmp_pc], 2);
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	}
	else if (dir_size == 0)
	{
		address = two_four_bytes(&skrr->map[process->tmp_pc], 4);
		process->tmp_pc = (process->tmp_pc + 3 + MEM_SIZE) % MEM_SIZE;
	}
	return (address);
}

/*
**	if l = 1 -> for long function, means without %IDX_MOD
*/

int		ind_param(t_skrr *skrr, t_proc *process, int bytes)
{
	int				address;
	unsigned int	ind[bytes];
	int				i;

	i = -1;
	skrr->shift = (bytes == 4) ? 24 : 8;
	address = (process->pc +
			((short)two_four_bytes(&skrr->map[process->tmp_pc], 2) % IDX_MOD));
	while (++i < bytes)
	{
		address = (address + MEM_SIZE) % MEM_SIZE;
		ind[i] = get_magic_size(skrr->map[address], skrr->shift);
		skrr->shift -= 8;
		address++;
	}
	address = (bytes == 4) ?
			(ind[0] | ind[1] | ind[2] | ind[3]) : (ind[0] | ind[1]);
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	return (address);
}
