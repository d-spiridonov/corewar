/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_secondary_functions_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 17:28:01 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 20:14:40 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		is_it_label(t_labels *tmp, int i)
{
	while (tmp->str[g_asm.p] != LABEL_CHAR &&
			!(ft_isspace(tmp->str[g_asm.p])))
	{
		if (!find_char(tmp->str[g_asm.p], 0))
			return (print_usage(4, "nope"));
		g_asm.p++;
	}
	if (tmp->str[g_asm.p] != LABEL_CHAR)
		return (print_usage(13, g_tab[i].name));
	else
		return (1);
}

char	*usage(void)
{
	t_file	*tmp;

	tmp = g_file;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->file_name);
}

char	*change_file_name(t_file *t)
{
	char	*str;
	char	*w;
	char	*e;

	while (t->next != NULL)
		t = t->next;
	e = t->file_name;
	str = ft_strsub(t->file_name, 0, ft_strlen(t->file_name) - 2);
	w = str;
	str = ft_strjoin(str, ".cor");
	free(w);
	free(e);
	return (str);
}

int		name_s(char *str, char *argv)
{
	int count;

	count = 0;
	if (str[0] == '-' && str[1] == 'a' && str[2] == '\0')
		return (1);
	while (ft_strchr(str, '/'))
	{
		while (*str != '/')
			str++;
		(*str == '/') ? str++ : 0;
	}
	while (str[count])
		count++;
	count--;
	if (str[count] == 's' && str[count - 1] == '.')
		return (1);
	return (print_usage_0(3, argv));
}

int		no_emty(t_file *t, int i, t_labels *tmp)
{
	while (t->next != NULL)
		t = t->next;
	tmp = t->labels;
	while (tmp != NULL)
	{
		while ((ft_isspace(tmp->str[i]) || (tmp->str[i] == '\0') ||
				(tmp->str[i] == COMMENT_CHAR) || tmp->str[i] == ';') &&
			(tmp->next != NULL))
		{
			while (ft_isspace(tmp->str[i]))
				i++;
			if ((tmp->str[i] == '\0' || tmp->str[i] == COMMENT_CHAR ||
				tmp->str[i] == ';') && tmp->next != NULL)
				tmp = tmp->next;
			while (ft_isspace(tmp->str[i]))
				i++;
		}
		if ((tmp->str[i] != '.') && (tmp->str[i] != COMMENT_CHAR) &&
				(tmp->str[i] != ';') && (tmp->str[i] != '\0') &&
				!ft_isspace(tmp->str[i]))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
