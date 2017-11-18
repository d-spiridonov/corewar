/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_create_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 13:45:55 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 20:24:52 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void			create_file(t_file *t)
{
	t_labels *tmp;

	lets_get_null_for_file();
	while (t->next != NULL)
		t = t->next;
	t->file_name = change_file_name(g_file);
	tmp = t->labels;
	prog_size_magic_n_c(t, tmp, 0, -1);
	g_asm.fd = open(t->file_name, O_RDWR | O_CREAT, 007700);
	if (g_asm.fd != -1)
	{
		write(g_asm.fd, &g_asm.header, (sizeof(g_asm.header)));
		write_body(tmp, 0);
	}
	print_usage(1, t->file_name);
}

void			write_body(t_labels *tmp, int i)
{
	while ((find_n_for_size(tmp, 15, 0) == -1) && tmp)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		g_asm.label = 0;
		if ((i = find_n_for_size(tmp, 15, 0)) > -1)
		{
			write(g_asm.fd, &g_tab[i].opcode, 1);
			(g_tab[i].codage == 1) ? write_codage(tmp, i, g_asm.label, 0) : 0;
			write_param(tmp, i);
		}
		tmp = tmp->next;
		g_asm.p = 0;
	}
}

void			write_param(t_labels *t, int i)
{
	int			number;
	char		*str;
	char		*w;

	number = g_tab[i].numb_of_arg;
	str = ft_strsub(t->str, (unsigned int)ft_strlen(g_tab[i].name) + 1,
					(ft_strlen(t->str) - ft_strlen(g_tab[i].name)));
	w = str;
	str += g_asm.label;
	while (ft_isspace(*str))
		str++;
	while (number > 0)
	{
		g_asm.li = 0;
		g_asm.ll = 0;
		if (*str == 'r')
			str = write_register(str, 0, 0);
		else if (*str == DIRECT_CHAR)
			str = write_direct(str, t, 0, i);
		else if (*str == LABEL_CHAR || *str == '-' || ft_isdigit(*str))
			str = write_indirect(str, t, 0);
		str = leaf_str(str);
		number--;
	}
	free(w);
}

int				write_codage(t_labels *t, int i, int p, int codage)
{
	p += ft_strlen(g_tab[i].name);
	while (ft_isspace(t->str[++p]))
		;
	if (g_tab[i].numb_of_arg == 1)
		codage = first_second_arg_codage(t, p, 1);
	else if (g_tab[i].numb_of_arg == 2)
	{
		codage = first_second_arg_codage(t, p, 1);
		p = leaf_p(t, p);
		codage = codage | first_second_arg_codage(t, p, 2);
	}
	else if (g_tab[i].numb_of_arg == 3)
	{
		codage = first_second_arg_codage(t, p, 1);
		p = leaf_p(t, p);
		codage = codage | first_second_arg_codage(t, p, 2);
		p = leaf_p(t, p);
		codage = codage | third_arg_codage(t, p);
	}
	if (g_asm.a == 1)
		return (codage);
	else
		write(g_asm.fd, &codage, 1);
	return (0);
}

void			prog_size_magic_n_c(t_file *t, t_labels *tm, int i, int q)
{
	while ((!(find_char(*tm->str, 0)) || (find_char(*tm->str, 0) &&
			tm->str[ft_strlen(tm->str) - 1] == '\n')) &&
			(find_n_for_size(tm, 15, 0) == -1))
		tm = tm->next;
	while (tm != NULL)
	{
		if ((i = find_n_for_size(tm, 15, 0)) > -1)
			count_par_b(g_tab[i].numb_of_arg, tm, i, (g_asm.p));
		g_asm.label = 0;
		tm = tm->next;
		g_asm.p = 0;
	}
	g_asm.header.prog_size = convert(g_asm.prog_size);
	g_asm.header.magic = convert(COREWAR_EXEC_MAGIC);
	while (t->name[++q])
		g_asm.header.prog_name[q] = t->name[q];
	while (q <= PROG_NAME_LENGTH + 1)
		g_asm.header.prog_name[q++] = '\0';
	q = -1;
	while (t->comm[++q])
		g_asm.header.comment[q] = t->comm[q];
	while (q <= COMMENT_LENGTH + 1)
		g_asm.header.comment[q++] = '\0';
}
