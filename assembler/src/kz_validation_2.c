/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_validation_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:07:51 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:41:04 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		checkout_body(t_labels *t, int a, int i)
{
	if ((i = find_n(t, 15, 0)) == -1)
	{
		while (t->str[g_asm.p] != LABEL_CHAR && !(ft_isspace(t->str[g_asm.p])))
		{
			if (!find_char(t->str[g_asm.p], 0))
				return (print_usage(4, "nope"));
			g_asm.p++;
		}
		(t->str[g_asm.p] != LABEL_CHAR) ? i = -2 : 0;
		g_asm.p++;
		while (ft_isspace(t->str[g_asm.p]))
			g_asm.p++;
		if (t->str[g_asm.p] == '\0' || t->str[g_asm.p] == COMMENT_CHAR ||
				t->str[g_asm.p] == ';')
			return (1);
		if ((a = find_n(t, 15, 0)) == -1)
			return (print_usage(8, "nope"));
		else if (i == -2)
			return (print_usage(11, "nope"));
		else if (!(check_param(t, a)))
			return (0);
	}
	else if (!(check_param(t, i)))
		return (0);
	return (1);
}

int		check_all_labels(int p)
{
	t_labels	*t;

	t = leaf_list(g_file);
	while (t != NULL)
	{
		p = 0;
		t = skip_blank_lines(t, -3);
		if (t->str[0] == '\0' && t->next == NULL)
			break ;
		if (find_n(t, 15, 0) == -1)
		{
			while (t->str[p] != LABEL_CHAR &&
				!(ft_isspace(t->str[p])))
			{
				if (!find_char(t->str[p], 0))
					return (print_usage_0(0, "nope"));
				p++;
			}
			if (t->str[p] != LABEL_CHAR || (t->str[p] == LABEL_CHAR && p == 0))
				return (print_usage_0(1, "nope"));
		}
		t = t->next;
		g_asm.count++;
	}
	return (1);
}

int		check_param(t_labels *tmp, int i)
{
	g_asm.p += ft_strlen(g_tab[i].name);
	if (!(ft_isspace(tmp->str[g_asm.p])))
		return (is_it_label(tmp, i));
	while (ft_isspace(tmp->str[g_asm.p]))
		g_asm.p++;
	if ((i == 0) || (i == 8) || (i == 11) || (i == 14) || (i == 15))
		return (instruction_with_one_param(tmp, i));
	else if ((i == 3) || (i == 4))
		return (instruction_with_three_param1_1_1(tmp, i));
	else if ((i == 5) || (i == 6) || (i == 7))
		return (instruction_with_three_param3_3_1(tmp, i));
	else if ((i == 1) || (i == 12))
		return (instruction_with_two_param2_1(tmp, i, 1));
	else if ((i == 9) || (i == 13))
		return (instruction_with_three_param3_2_1(tmp, i));
	else if (i == 10)
		return (instruction_with_three_param1_3_2(tmp, i));
	else if (i == 2)
		return (instruction_with_two_param2_1(tmp, i, 2));
	return (0);
}

int		instruction_with_one_param(t_labels *tmp, int i)
{
	if (g_tab[i].arg[0] == T_DIR)
		return (check_direct(tmp, i, 0, -1));
	else if (g_tab[i].arg[0] == T_REG)
		return (check_registry(tmp, i, 0, -1));
	return (0);
}

int		find_n(t_labels *tmp, int i, int l)
{
	char	*t;
	int		d;

	if (tmp == NULL)
		return (-1);
	t = tmp->str;
	t += (l == 0) ? g_asm.p : g_asm.lc;
	while (i >= 0)
	{
		d = (l == 0) ? g_asm.p : g_asm.lc;
		d += ft_strlen(g_tab[i].name);
		if (!(ft_strncmp(g_tab[i].name, t, ft_strlen(g_tab[i].name))))
		{
			if (find_char(tmp->str[d], 0))
				return (-1);
			if (tmp->str[d] != LABEL_CHAR)
			{
				return (i);
			}
		}
		i--;
	}
	return (-1);
}
