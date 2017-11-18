/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_find_label_to_write.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:04:12 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 20:02:02 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

#define S(c) ((c) == '\n' ? 1 : 0)

char	*print_label(char *s, unsigned int q, t_labels *t, int dir)
{
	s++;
	find_label_to_writ(s, t, 0, 0);
	find_line_for_instruction(t, g_file);
	q = (unsigned int)(find_size_of_prog_here(g_asm.ll - 1, g_file) -
							find_size_of_prog_here(g_asm.li - 1, g_file));
	(dir == 1) ? q = swap(q, DIR_SIZE) : 0;
	(dir == 1) ? write(g_asm.fd, &q, DIR_SIZE) : 0;
	if (dir == 0)
	{
		q = swap(q, DIR_SIZE + 2);
		write(g_asm.fd, &q, DIR_SIZE + 2);
	}
	else if (dir == 2)
	{
		q = swap(q, IND_SIZE);
		write(g_asm.fd, &q, IND_SIZE);
	}
	return (s);
}

int		find_label_to_writ(char *str, t_labels *t, int c, size_t i)
{
	char		*s;
	char		*w;

	t = leaf(g_file, t);
	while ((!(find_char(*t->str, 0)) || (find_char(*t->str, 0) && \
		S(t->str[ft_strlen(t->str) - 1]))) && (find_n_for_size(t, 15, 0) == -1))
	{
		t = t->next;
		g_asm.ll++;
	}
	while (str[c] != SEPARATOR_CHAR && str[c] != COMMENT_CHAR && str[c] != ';'
			&& !(ft_isspace(str[c])) && str[c])
		c++;
	s = ft_strsub(str, 0, (size_t)c);
	w = s;
	while (ft_strncmp(s, t->str, ft_strlen(s)) || (ft_strlen(s) < i))
	{
		t = t->next;
		g_asm.ll++;
		i = 0;
		while (t->str[i] && (t->str[i] != LABEL_CHAR))
			i++;
	}
	free(w);
	return (g_asm.ll);
}

int		find_line_for_instruction(t_labels *tmp, t_file *t)
{
	t_labels	*fn;

	while (t->next != NULL)
		t = t->next;
	fn = t->labels;
	while (ft_strncmp(tmp->str, fn->str, ft_strlen(tmp->str)))
	{
		fn = fn->next;
		g_asm.li++;
	}
	if ((g_asm.last_line != 0) && (g_asm.last_line >= g_asm.li))
	{
		fn = fn->next;
		g_asm.li++;
		while (fn && ((g_asm.last_line + 1 >= g_asm.li) ||
				ft_strncmp(tmp->str, fn->str, ft_strlen(tmp->str))))
		{
			fn = fn->next;
			g_asm.li++;
		}
	}
	g_asm.last_line = g_asm.li;
	return (g_asm.li);
}

int		find_size_of_prog_here(int line, t_file *t)
{
	int			size;
	t_labels	*tmp;
	int			i;

	size = 0;
	while (t->next != NULL)
		t = t->next;
	tmp = t->labels;
	while (!(find_char(*tmp->str, 0)) &&
			(find_n_for_size(tmp, 15, 0) == -1) && line)
	{
		tmp = tmp->next;
		line--;
	}
	while (tmp && line >= 0)
	{
		if ((i = find_n_for_size(tmp, 15, 0)) > -1)
			size += count_par_fn(g_tab[i].numb_of_arg, tmp, i, 0);
		g_asm.label = 0;
		tmp = tmp->next;
		line--;
	}
	return (size);
}
