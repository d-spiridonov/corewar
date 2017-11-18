/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:49:23 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 20:20:36 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void		print_with_a(t_file *t)
{
	t_labels *tmp;

	lets_get_null_for_file();
	ft_printf(UNDER "Dumping annotated program on standard output\n" RESET);
	lets_get_null_for_file();
	while (t->next != NULL)
		t = t->next;
	t->file_name = change_file_name(g_file);
	tmp = t->labels;
	ft_printf("Program size : %d bytes\n", prog_size(tmp, 0));
	ft_printf("Name : \"%s\"\n", t->name);
	ft_printf("Comment : \"%s\"\n\n", t->comm);
	print_body(tmp, 0, 0, 0);
}

void		print_body(t_labels *tmp, int i, int before, int after)
{
	while (!find_char(*tmp->str, 0) && (find_n_for_size(tmp, 15, 0) == -1)
							&& tmp)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		tmp = skip_blank_lines(tmp, 0);
		g_asm.label = 0;
		if ((i = find_n_for_size(tmp, 15, 0)) > -1)
		{
			g_asm.label1 = g_asm.label;
			g_asm.li = 0;
			g_asm.ll = 0;
			after = before;
			before = find_size_of_prog_here(fnd_l_for_ins_a(tmp, g_file,
				g_asm.last_mas, 0), g_file);
			(g_asm.label1 > 0) ? print_label_output(after, tmp) : 0;
			ft_printf("%-4d(%-3d) :\t   ", after, before - after);
			print_instruction(tmp, i, 0);
		}
		else
			print_label_output(before, tmp);
		g_asm.p = 0;
		tmp = tmp->next;
	}
}

void		print_instruction(t_labels *tmp, int i, int count)
{
	char	*s;
	int		n;
	int		c;

	g_asm.p = g_asm.label1;
	ft_printf("%-10s", g_tab[i].name);
	g_asm.p += ft_strlen(g_tab[i].name);
	while (ft_isspace(tmp->str[g_asm.p]))
		g_asm.p++;
	c = g_asm.p;
	while (count < g_tab[i].numb_of_arg)
	{
		n = g_asm.p;
		while (!ft_isspace(tmp->str[g_asm.p]) &&
			tmp->str[g_asm.p] != SEPARATOR_CHAR && tmp->str[g_asm.p] != ';'
			&& tmp->str[g_asm.p] != COMMENT_CHAR && tmp->str[g_asm.p] != '\0')
			g_asm.p++;
		s = ft_strsub(tmp->str, (unsigned int)n, (size_t)(g_asm.p - n));
		ft_printf("%-18s", s) ? free(s) : 0;
		while ((ft_isspace(tmp->str[g_asm.p]) ||
				tmp->str[g_asm.p] == SEPARATOR_CHAR) && tmp->str)
			g_asm.p++;
		count++;
	}
	print_details(tmp, i, 0, c);
}

void		print_label_output(int before, t_labels *tmp)
{
	char	*s;
	size_t	count;

	count = 0;
	if (tmp->str[count] == '\0')
		return ;
	while (tmp->str[count] != LABEL_CHAR)
		count++;
	count++;
	s = ft_strsub(tmp->str, 0, count);
	if (s[0] == '\0')
	{
		free(s);
		return ;
	}
	ft_printf("%-9d :    %s\n", before, s);
	free(s);
}

int			prog_size(t_labels *tmp, int i)
{
	while ((!(find_char(*tmp->str, 0)) || (find_char(*tmp->str, 0) &&
			tmp->str[ft_strlen(tmp->str) - 1] == '\n')) &&
			(find_n(tmp, 15, 0) == -1))
		tmp = tmp->next;
	while (tmp != NULL)
	{
		if ((i = find_n_for_size(tmp, 15, 0)) > -1)
			count_par_b(g_tab[i].numb_of_arg, tmp, i, (g_asm.p));
		tmp = tmp->next;
		g_asm.p = 0;
	}
	return (g_asm.prog_size);
}
