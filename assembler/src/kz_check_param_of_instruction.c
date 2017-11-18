/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_check_param_of_instruction.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:00:32 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:34:04 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		check_direct(t_labels *t, int i, int q, int last)
{
	g_asm.last = last;
	if (t->str[g_asm.p] != DIRECT_CHAR)
		return (print_usage_1(0, g_tab[i].name, q, "direct"));
	g_asm.p++;
	if (t->str[g_asm.p] == LABEL_CHAR || t->str[g_asm.p] == '-' ||
		ft_isdigit(t->str[g_asm.p]))
	{
		if (t->str[g_asm.p] == LABEL_CHAR)
		{
			if (find_label(t, g_file, i, 0))
				return (check_separator(t, q, i));
			return (0);
		}
		(t->str[g_asm.p] == '-') ? g_asm.p++ : 0;
		while ((t->str[g_asm.p] != SEPARATOR_CHAR) &&
				t->str[g_asm.p] != COMMENT_CHAR && t->str[g_asm.p] != ';' &&
				!(ft_isspace(t->str[g_asm.p])) && (t->str[g_asm.p] != '\0'))
		{
			if (!(ft_isdigit(t->str[g_asm.p])))
				return (print_usage(4, "nope"));
			g_asm.p++;
		}
		return (check_separator(t, q, i));
	}
	return (print_usage(4, "nope"));
}

int		check_registry(t_labels *tmp, int i, int q, int last)
{
	char	*str;
	char	*w;

	g_asm.last = last;
	str = ft_strdup(tmp->str);
	w = str;
	if (tmp->str[g_asm.p] != 'r')
		return (print_usage_1(0, g_tab[i].name, q, "registry"));
	g_asm.p++;
	if (ft_isdigit(tmp->str[g_asm.p]))
	{
		str += g_asm.p;
		free(w);
		while (tmp->str[g_asm.p] != SEPARATOR_CHAR &&
				tmp->str[g_asm.p] != COMMENT_CHAR && tmp->str[g_asm.p] != ';'
				&& !ft_isspace(tmp->str[g_asm.p]) && tmp->str[g_asm.p] != '\0')
			if (!(for_check_registry(tmp, str)))
				return (print_usage(11, "nope"));
		return (check_separator(tmp, q, i));
	}
	else
		free(w);
	return (print_usage(11, "nope"));
}

int		check_indirect(t_labels *tmp, int i, int q, int last)
{
	g_asm.last = last;
	if (tmp->str[g_asm.p] == LABEL_CHAR || tmp->str[g_asm.p] == '-' ||
		ft_isdigit(tmp->str[g_asm.p]))
	{
		if (tmp->str[g_asm.p] == LABEL_CHAR)
		{
			if (find_label(tmp, g_file, i, 0))
				return (check_separator(tmp, q, i));
			return (0);
		}
		if (tmp->str[g_asm.p] == '-')
			g_asm.p++;
		while ((tmp->str[g_asm.p] != SEPARATOR_CHAR) &&
				tmp->str[g_asm.p] != COMMENT_CHAR && tmp->str[g_asm.p] != ';' &&
				!(ft_isspace(tmp->str[g_asm.p])) && (tmp->str[g_asm.p] != '\0'))
		{
			if (!(ft_isdigit(tmp->str[g_asm.p])))
				return (print_usage(4, "nope"));
			g_asm.p++;
		}
		return (check_separator(tmp, q, i));
	}
	else
		return (print_usage(4, "nope"));
}

int		check_separator(t_labels *tmp, int q, int i)
{
	while (ft_isspace(tmp->str[g_asm.p]))
		g_asm.p++;
	if (tmp->str[g_asm.p] == SEPARATOR_CHAR && g_asm.last != -1)
		return (1);
	if (tmp->str[g_asm.p] != SEPARATOR_CHAR && g_asm.last != -1)
		return (print_usage(11, "nope"));
	if ((tmp->str[g_asm.p] == COMMENT_CHAR || tmp->str[g_asm.p] == ';') &&
			g_asm.last == -1)
		return (1);
	if (tmp->str[g_asm.p] == SEPARATOR_CHAR && g_asm.last == -1)
		return (print_usage_1(2, g_tab[i].name, q, "nope"));
	if (ft_isspace(tmp->str[g_asm.p]) && g_asm.last == -1)
	{
		while (ft_isspace(tmp->str[g_asm.p]) && tmp->str[g_asm.p] != '\0')
			g_asm.p++;
		if (tmp->str[g_asm.p] != '\0' && tmp->str[g_asm.p] != COMMENT_CHAR &&
				tmp->str[g_asm.p] != ';')
			return (print_usage(11, "nope"));
		else
			return (1);
	}
	if (tmp->str[g_asm.p] == '\0' && g_asm.last == -1)
		return (1);
	return (0);
}

int		find_label(t_labels *q, t_file *t, int i, size_t c)
{
	t_labels	*fn;
	char		*str;

	fn = leaf(t, q);
	g_asm.p++;
	while (q->str[g_asm.p + c] != SEPARATOR_CHAR &&
			q->str[g_asm.p + c] != COMMENT_CHAR && q->str[g_asm.p + c] != ';' &&
			!(ft_isspace(q->str[g_asm.p + c])) && q->str[g_asm.p + c] != '\0')
		c++;
	str = q->str;
	str += g_asm.p;
	g_asm.p += c;
	while (fn != NULL)
	{
		skip_blank_lines(fn, -1);
		if (!(ft_strncmp(str, fn->str, c)) && fn->str[c] == LABEL_CHAR)
			return (1);
		fn = fn->next;
	}
	return (print_usage_1(3, g_tab[i].name, 0, "nope"));
}
