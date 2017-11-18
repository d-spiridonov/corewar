/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_help_to_valid_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 21:57:43 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 20:33:14 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		find_n_for_size(t_labels *tmp, int i, int l)
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
				return (i);
			if (tmp->str[d] == LABEL_CHAR && find_after_l(tmp, d, i, t) >= 0)
				return (i);
		}
		else if (find_after_l(tmp, d, i, t) >= 0)
			return (i);
		i--;
	}
	return (-1);
}

int		find_after_l(t_labels *tmp, int d, int i, char *t)
{
	int q;

	q = 0;
	while (tmp->str[q] && tmp->str[q] != LABEL_CHAR)
		q++;
	q++;
	if (tmp->str[q] == '\0')
		return (-1);
	while (tmp->str[q] && ft_isspace(tmp->str[q]))
		q++;
	(ft_strlen(t) > (size_t)q) ? t += q : 0;
	if (!(ft_strncmp(g_tab[i].name, t, ft_strlen(g_tab[i].name))))
	{
		d = 0;
		d += ft_strlen(g_tab[i].name);
		if (find_char(t[d], 0))
			return (-1);
		if (t[d] != LABEL_CHAR)
		{
			g_asm.label = q;
			return (i);
		}
	}
	return (-1);
}

int		count_n(t_labels *tmp, int n, int i)
{
	n = i + 1;
	while (ft_isspace(tmp->str[n]))
		n++;
	if (tmp->str[n] == COMMENT_CHAR || tmp->str[n] == ';')
		while (tmp->str[n])
			n++;
	return (n);
}

void	name_co(t_file *tmp, t_labels *t, int a)
{
	char	*w;

	w = t->str;
	if (a == 1)
		tmp->name = ft_strsub(t->str, (unsigned int)g_asm.s + 1,
								ft_strlen(t->str) - g_asm.s);
	else
		tmp->comm = ft_strsub(t->str, (unsigned int)g_asm.s + 1,
								ft_strlen(t->str) - g_asm.s);
	free(w);
}

int		for_check_registry(t_labels *tmp, char *str)
{
	if (!(ft_isdigit(tmp->str[g_asm.p])) || (ft_atoi(str) < 0) ||
		(ft_atoi(str) > REG_NUMBER))
		return (0);
	g_asm.p++;
	return (1);
}
