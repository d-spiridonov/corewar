/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_n_in_name_or_comm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:46:19 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:36:49 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int			find_quote(t_labels *tmp, int i, int n, int a)
{
	char *w;

	g_asm.t = g_asm.l;
	w = tmp->str;
	(tmp->str = ft_strjoin(tmp->str, "\n")) != NULL ? free(w) : 0;
	while (tmp->str[i + g_asm.p] != '"')
	{
		g_asm.p = 0;
		i = 0;
		g_asm.l++;
		tmp = tmp->next;
		if (tmp == NULL)
			return (print_usage(11, "none"));
		while (tmp->str[i] != '"' && tmp->str[i] != '\0')
			i++;
		w = tmp->str;
		(tmp->str[i] == '\0') ? tmp->str = ft_strjoin(tmp->str, "\n") : 0;
		free(w);
		if (tmp->str[i] == '"')
			break ;
	}
	n = count_n(tmp, n, i);
	if (tmp->str[n] != '\0')
		return (print_usage(11, "none"));
	return (finaly_check_n_n(g_file, i, a, tmp));
}

int			finaly_check_n_n(t_file *tmp, int i, int a, t_labels *t)
{
	int d;

	d = 1;
	while (tmp->next != NULL)
		tmp = tmp->next;
	t = tmp->labels;
	while (t && (d != g_asm.t))
	{
		t = t->next;
		d++;
	}
	while (t && t->str[g_asm.s] != '"')
		g_asm.s++;
	if (t && t->str[g_asm.s] == '"')
	{
		while (g_asm.t < g_asm.l)
			t = check_n_n(tmp, i, a, t);
		if (g_asm.t == g_asm.l)
		{
			g_asm.w = -100;
			write_fu_name_comm(tmp, t, a, i);
		}
		return (1);
	}
	return (0);
}

void		write_fu_name_comm(t_file *tmp, t_labels *t, int a, int i)
{
	char	*fn;
	char	*w;

	if (g_asm.w == 0)
		name_co(tmp, t, a);
	else if (g_asm.w > 0)
	{
		w = (a == 1) ? tmp->name : tmp->comm;
		(a == 1) ? tmp->name = ft_strjoin(tmp->name, t->str) : 0;
		(a != 1) ? tmp->comm = ft_strjoin(tmp->comm, t->str) : 0;
		free(w);
	}
	else if (g_asm.w == -100)
	{
		w = (a == 1) ? tmp->name : tmp->comm;
		fn = ft_strsub(t->str, 0, (size_t)i);
		(a == 1) ? tmp->name = ft_strjoin(tmp->name, fn) : 0;
		(a != 1) ? tmp->comm = ft_strjoin(tmp->comm, fn) : 0;
		free(w);
	}
}
