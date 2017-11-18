/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_validation_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 16:11:51 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:40:53 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		g_validation(char *str, char *line)
{
	char			c[1];
	static int		y;

	if (!(str[0] == '-' && str[1] == 'a' && str[2] == '\0'))
	{
		y++;
		if ((g_asm.fd = open(str, O_RDONLY)) == -1)
		{
			y--;
			return (print_usage(2, str));
		}
		g_file = record_file(str, y);
		if (lseek(g_asm.fd, -1, SEEK_END) < 0 || (read(g_asm.fd, c, 1) < 0) ||
				(lseek(g_asm.fd, 0, SEEK_SET) < 0))
			return (print_usage(10, "Seek/Read Error"));
		while (get_next_line(g_asm.fd, &line) > 0)
			record_labels(line) == 1 ? free(line) : 0;
		if (((g_asm.q = looking_for_errors(g_file, 1)) == 1) && c[0] != '\n')
			return (print_usage(9, str));
		else if (g_asm.q > 0)
			return (1);
	}
	return (0);
}

int		looking_for_errors(t_file *t, int n)
{
	t_labels	*tmp;

	while (t->next != NULL)
		t = t->next;
	tmp = t->labels;
	if (!(no_emty(g_file, 0, t->labels)))
		return (print_usage_0(2, "nope"));
	while (tmp != NULL)
	{
		g_asm.p = 0;
		tmp = skip_blank_lines(tmp, 1);
		if (tmp->str[g_asm.p] == '\0' && tmp->next == NULL)
			return (2);
		if (g_asm.line == 1 || g_asm.line == 2)
			if ((tmp = name_comm(tmp, n, 0)) == 0)
				return (0);
		if (g_asm.line > 2 && tmp->str[g_asm.p])
			if ((tmp = name_comm(tmp, n, 1)) == 0)
				return (0);
		tmp = tmp->next;
		g_asm.line++;
		g_asm.l++;
	}
	return (name_length(t));
}

int		checkout_name_comm(t_labels *tmp, int a)
{
	tmp = skip_blank_lines(tmp, 1);
	if (!(ft_strncmp(NAME_CMD_STRING, tmp->str, 5)))
	{
		g_asm.p += 5;
		g_asm.f_name++;
		a = 1;
	}
	else if (!(ft_strncmp(COMMENT_CMD_STRING, tmp->str, 8)))
	{
		g_asm.p += 8;
		g_asm.f_comment++;
	}
	else if (check_no_repit(tmp))
		return (print_usage(3, "none"));
	else
		return (0);
	while (ft_isspace(tmp->str[g_asm.p]))
		g_asm.p++;
	if (check_no_repit(tmp))
		return (check_comment(tmp, 0, a));
	return (0);
}

int		check_comment(t_labels *tmp, int i, int a)
{
	int		n;

	n = 0;
	if (tmp->str[g_asm.p] == '"')
	{
		g_asm.p++;
		while (tmp->str[g_asm.p + i] != '"' && tmp->str[g_asm.p + i] != '\0')
			i++;
		if (tmp->str[g_asm.p + i] == '\0')
			return (find_quote(tmp, i, n, a));
		n = g_asm.p + i + 1;
		while (ft_isspace(tmp->str[n]))
			n++;
		if (tmp->str[n] == COMMENT_CHAR || tmp->str[n] == ';')
			while (tmp->str[n])
				n++;
		if (finaly_check_name_comm(tmp, g_asm.p + i, n, a))
			return (1);
		else
			print_usage(11, "none");
	}
	else
		print_usage(4, "none");
	return (0);
}

int		check_no_repit(t_labels *tmp)
{
	if (g_asm.line == 2 && (g_asm.f_name == 0 || g_asm.f_comment == 0))
	{
		if ((g_asm.f_name == 0) && (g_asm.f_comment > 1))
			print_usage(5, ".comment");
		else if ((g_asm.f_comment == 0) && (g_asm.f_name > 1))
			print_usage(6, ".name");
		else
			print_usage(7, tmp->str);
		return (0);
	}
	return (1);
}
