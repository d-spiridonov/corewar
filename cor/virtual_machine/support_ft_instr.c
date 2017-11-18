/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_ft_instr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:34:54 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/24 12:54:19 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		supp_to_and(unsigned char *q, t_skrr *skrr, short i, t_proc *process)
{
	int adr;

	adr = 0;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
		if (!(adr = reg_param(skrr, process, 1)) && (g_err))
			return (0);
	if (q[i] == T_DIR)
		adr = dir_param(skrr, process, g_tab[skrr->op].dir_size);
	if (q[i] == T_IND)
		adr = ind_param(skrr, process, 4);
	i++;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
	{
		adr &= reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	if (q[i] == T_DIR)
		adr &= dir_param(skrr, process, g_tab[skrr->op].dir_size);
	if (q[i] == T_IND)
		adr &= ind_param(skrr, process, 4);
	return (adr);
}

int		supp_to_or(unsigned char *q, t_skrr *skrr, short i, t_proc *process)
{
	int adr;

	adr = 0;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
		if (!(adr = reg_param(skrr, process, 1)) && (g_err))
			return (0);
	if (q[i] == T_DIR)
		adr = dir_param(skrr, process, g_tab[skrr->op].dir_size);
	if (q[i] == T_IND)
		adr = ind_param(skrr, process, 4);
	i++;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
	{
		adr |= reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	if (q[i] == T_DIR)
		adr |= dir_param(skrr, process, g_tab[skrr->op].dir_size);
	if (q[i] == T_IND)
		adr |= ind_param(skrr, process, 4);
	return (adr);
}

int		supp_to_xor(unsigned char *q, t_skrr *skrr, short i, t_proc *process)
{
	int	adr;

	adr = 0;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
		if (!(adr = reg_param(skrr, process, 1)) && (g_err))
			return (0);
	if (q[i] == T_DIR)
		adr = dir_param(skrr, process, g_tab[skrr->op].dir_size);
	if (q[i] == T_IND)
		adr = ind_param(skrr, process, 4);
	i++;
	process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
	if (q[i] == T_REG)
	{
		adr ^= reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	if (q[i] == T_DIR)
		adr ^= dir_param(skrr, process, g_tab[skrr->op].dir_size);
	if (q[i] == T_IND)
		adr ^= ind_param(skrr, process, 4);
	return (adr);
}

int		supp_add_sub(t_skrr *skrr, int key, t_proc *process)
{
	int adr;

	adr = 0;
	if (key == 1)
	{
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		if (!(adr = reg_param(skrr, process, 1)) && (g_err))
			return (0);
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		adr += reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	if (key == 2)
	{
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		if (!(adr = reg_param(skrr, process, 1)) && (g_err))
			return (0);
		process->tmp_pc = (process->tmp_pc + 1 + MEM_SIZE) % MEM_SIZE;
		adr -= reg_param(skrr, process, 1);
		if (g_err)
			return (0);
	}
	return (adr);
}

int		det_of_action(unsigned char *q, t_skrr *skrr, int key, t_proc *process)
{
	int		result;
	short	i;

	result = 0;
	i = 0;
	if (key == 1)
		if (!(result = supp_add_sub(skrr, key, process)) && (g_err))
			return (0);
	if (key == 2)
		if (!(result = supp_add_sub(skrr, key, process)) && (g_err))
			return (0);
	if (key == 3)
		if (!(result = supp_to_and(q, skrr, i, process)) && (g_err))
			return (0);
	if (key == 4)
		if (!(result = supp_to_or(q, skrr, i, process)) && (g_err))
			return (0);
	if (key == 5)
		if (!(result = supp_to_xor(q, skrr, i, process)) && (g_err))
			return (0);
	return (result);
}
