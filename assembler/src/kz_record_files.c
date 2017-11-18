/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_record_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:26:28 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:39:33 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int			record_labels(char *line)
{
	t_file		*q;

	q = g_file;
	while (q->next != NULL)
		q = q->next;
	if (g_asm.c == 0)
	{
		q->labels = (t_labels *)malloc(sizeof(t_labels));
		q->labels->str = ft_strdup(line);
		q->labels->next = NULL;
	}
	if (g_asm.c != 0)
		add_label(line, q->labels);
	g_asm.c++;
	return (1);
}

t_file		*record_file(char *str, int y)
{
	t_file		*tmp;

	tmp = g_file;
	if (y == 1)
	{
		tmp = (t_file *)malloc(sizeof(t_file));
		tmp->file_name = ft_strdup(str);
		tmp->name = NULL;
		tmp->comm = NULL;
		tmp->labels = NULL;
		tmp->next = NULL;
	}
	if (y != 1)
		add_file(tmp, str);
	return (tmp);
}

void		add_label(char *line, t_labels *labels)
{
	t_labels *tmp;

	tmp = labels;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_labels *)malloc(sizeof(t_labels));
	tmp->next->str = ft_strdup(line);
	tmp->next->next = NULL;
}

void		add_file(t_file *file, char *str)
{
	t_file *tmp;

	tmp = file;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_file *)malloc(sizeof(t_file));
	tmp->next->file_name = ft_strdup(str);
	tmp->next->name = NULL;
	tmp->next->comm = NULL;
	tmp->next->labels = NULL;
	tmp->next->next = NULL;
}
