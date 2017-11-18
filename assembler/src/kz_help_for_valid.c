/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_help_for_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:02:01 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:35:24 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

t_labels	*name_comm(t_labels *tmp, int n, int a)
{
	if (a == 0)
	{
		n = g_asm.l;
		if (!(checkout_name_comm(tmp, 0)))
			return (0);
		if (g_asm.l > n)
		{
			n = g_asm.l - n;
			while (n > 0)
			{
				tmp = tmp->next;
				n--;
			}
		}
		g_asm.w = 0;
	}
	else if (a == 1)
	{
		if (g_asm.line == 3)
			if (!(check_all_labels(g_asm.p)))
				return (0);
		if (!(checkout_body(tmp, 0, 0)))
			return (0);
	}
	return (tmp);
}

char		*leaf_str(char *str)
{
	while (*str != SEPARATOR_CHAR && !(ft_isspace(*str)) && *str)
		str++;
	while (*str == SEPARATOR_CHAR || ft_isspace(*str))
		str++;
	return (str);
}

int			name_length(t_file *t)
{
	if (ft_strlen(t->name) > PROG_NAME_LENGTH)
		return (print_usage(12, "Champion name too long (Max length 128)"));
	if (ft_strlen(t->comm) > COMMENT_LENGTH)
		return (print_usage(12, "Champion comment too long (Max length 2048)"));
	return (1);
}

t_labels	*check_n_n(t_file *tmp, int i, int a, t_labels *t)
{
	write_fu_name_comm(tmp, t, a, i);
	g_asm.t++;
	g_asm.w++;
	t = t->next;
	return (t);
}

t_labels	*leaf(t_file *t, t_labels *tmp)
{
	while (t->next != NULL)
		t = t->next;
	tmp = t->labels;
	return (tmp);
}
