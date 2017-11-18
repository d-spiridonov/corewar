/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_secondary_functions_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:09:01 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:40:10 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

t_labels	*leaf_list(t_file *t)
{
	t_labels	*tmp;

	g_asm.count = g_asm.l;
	while (t->next != NULL)
		t = t->next;
	tmp = t->labels;
	while (--g_asm.count > 0)
		tmp = tmp->next;
	g_asm.count = g_asm.l;
	return (tmp);
}

void		skip_separator_between_param(t_labels *tmp)
{
	if (tmp->str[g_asm.p] == SEPARATOR_CHAR)
		g_asm.p++;
	while (ft_isspace(tmp->str[g_asm.p]))
		g_asm.p++;
}

int			check_three(t_labels *tmp, int i, int number)
{
	if (tmp->str[g_asm.p] == DIRECT_CHAR)
		return (check_direct(tmp, i, number, 1));
	else if (tmp->str[g_asm.p] == 'r')
		return (check_registry(tmp, i, number, 1));
	else if (tmp->str[g_asm.p] == LABEL_CHAR || tmp->str[g_asm.p] == '-' ||
				ft_isdigit(tmp->str[g_asm.p]))
		return (check_indirect(tmp, i, number, 1));
	return (print_usage_1(4, g_tab[i].name, number, "nope"));
}

int			check_two(t_labels *tmp, int i, int hm, int number)
{
	if (hm == 2)
	{
		if (tmp->str[g_asm.p] == DIRECT_CHAR)
			return (check_direct(tmp, i, number, 1));
		else if (tmp->str[g_asm.p] == LABEL_CHAR || tmp->str[g_asm.p] == '-' ||
				ft_isdigit(tmp->str[g_asm.p]))
			return (check_indirect(tmp, i, number, 1));
	}
	if (hm == 20)
	{
		if (tmp->str[g_asm.p] == DIRECT_CHAR)
			return (check_direct(tmp, i, number, -1));
		else if (tmp->str[g_asm.p] == LABEL_CHAR || tmp->str[g_asm.p] == '-' ||
				ft_isdigit(tmp->str[g_asm.p]))
			return (check_indirect(tmp, i, number, -1));
	}
	if (hm == 30)
	{
		if (tmp->str[g_asm.p] == 'r')
			return (check_registry(tmp, i, number, -1));
		else if (tmp->str[g_asm.p] == LABEL_CHAR || tmp->str[g_asm.p] == '-' ||
				ft_isdigit(tmp->str[g_asm.p]))
			return (check_indirect(tmp, i, number, -1));
	}
	return (print_usage_1(4, g_tab[i].name, number, "nope"));
}

int			check_two_1(t_labels *tmp, int i, int hm, int number)
{
	if (hm == 2)
	{
		if (tmp->str[g_asm.p] == DIRECT_CHAR)
			return (check_direct(tmp, i, number, 1));
		else if (tmp->str[g_asm.p] == 'r')
			return (check_registry(tmp, i, 2, 1));
	}
	if (hm == 20)
	{
		if (tmp->str[g_asm.p] == DIRECT_CHAR)
			return (check_direct(tmp, i, number, -1));
		else if (tmp->str[g_asm.p] == 'r')
			return (check_registry(tmp, i, 2, -1));
	}
	return (print_usage_1(4, g_tab[i].name, number, "nope"));
}
