/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_load_from_into.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:31:50 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/10 17:31:51 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
**	flag = 1 -> , 2 -> for load on the map from reg 4 bytes value
*/

int		four_bytes(int address, t_proc *process, t_skrr *skrr)
{
	unsigned int	value[4];
	int				reg;

	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	while (++skrr->j < 4)
	{
		address = (address + MEM_SIZE) % MEM_SIZE;
		value[skrr->j] = get_magic_size(skrr->map[address], skrr->shift);
		skrr->shift -= 8;
		address++;
	}
	if (!(reg = reg_param(skrr, process, 2)) && (g_err))
		return (0);
	process->registry[reg] = value[0] | value[1] | value[2] | value[3];
	if (g_tab[skrr->op].opcode == 14 || g_tab[skrr->op].opcode == 13)
		process->carry = (process->registry[reg] == 0) ? 1 : 0;
	return (1);
}

int		load_into(int address, t_proc *process, t_skrr *skrr, int flag)
{
	skrr->j = -1;
	skrr->shift = 24;
	if (flag == 1)
	{
		while (++skrr->j < 4)
		{
			address = (address + MEM_SIZE) % MEM_SIZE;
			skrr->mapid[address] = (unsigned char)(process->id * -10);
			skrr->map[address++] = (unsigned char)
					(skrr->chmp->reg_value >> skrr->shift & 0x000000ff);
			skrr->shift -= 8;
		}
	}
	else if (flag == 2)
		if (!(four_bytes(address, process, skrr)) && (g_err))
			return (0);
	return (1);
}

int		from_reg(unsigned char *q, t_proc *process, t_skrr *skrr, short i)
{
	skrr->chmp->reg_value = 0;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
		skrr->chmp->reg_value = (unsigned int)reg_param(skrr, process, 1);
	else if (q[i] == T_DIR)
		skrr->chmp->reg_value = (unsigned int)dir_param(skrr, process, 1);
	else if (q[i] == T_IND)
		skrr->chmp->reg_value = (unsigned int)ind_param(skrr, process, 4);
	if (g_err == 1)
	{
		free(q);
		return (0);
	}
	return (1);
}

/*
**	l = 1 -> long instr, 0 for regular with IDX_MOD
*/

int		get_address(unsigned char *q, t_skrr *skrr, t_proc *process, short i)
{
	int adr;

	adr = 0;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
		if ((adr = reg_param(skrr, process, 1)) && (g_err))
			return (0);
	if (q[i] == T_DIR)
		adr = dir_param(skrr, process, 1);
	if (q[i] == T_IND)
		adr = ind_param(skrr, process, 4);
	i++;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
	{
		adr += reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	if (q[i] == T_DIR)
		adr += dir_param(skrr, process, 1);
	if (q[i] == T_IND)
		adr += ind_param(skrr, process, 4);
	return (adr);
}

int		simple_address(unsigned char *q, t_skrr *skrr, t_proc *process, short i)
{
	int adr;

	adr = 0;
	if (q[i] == T_IND)
	{
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		adr = (short)two_four_bytes(&skrr->map[process->tmp_pc], 2);
		adr = (process->pc + (adr % IDX_MOD));
	}
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
		if (!(adr = reg_param(skrr, process, 2)) && (g_err))
			return (0);
	return (adr);
}
