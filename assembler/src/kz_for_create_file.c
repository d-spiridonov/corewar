/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_for_create_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 20:16:39 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 19:13:44 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

char	*write_direct(char *s, t_labels *t, unsigned int q, int i)
{
	int		c;
	char	*w;

	c = 0;
	w = NULL;
	s++;
	if (*s == LABEL_CHAR)
		s = print_label(s, q, t, g_tab[i].dir_size);
	else
	{
		while (s[c] != SEPARATOR_CHAR && !(ft_isspace(s[c])) && s[c])
			c++;
		w = ft_strsub(s, 0, (size_t)c);
		q = (unsigned int)ft_atoi(w);
		(g_tab[i].dir_size == 1) ? q = swap(q, DIR_SIZE) : 0;
		(g_tab[i].dir_size == 1) ? write(g_asm.fd, &q, DIR_SIZE) : 0;
		(g_tab[i].dir_size != 1) ? q = swap(q, DIR_SIZE + 2) : 0;
		(g_tab[i].dir_size != 1) ? write(g_asm.fd, &q, DIR_SIZE + 2) : 0;
	}
	free(w);
	return (s);
}

char	*write_indirect(char *s, t_labels *t, unsigned int q)
{
	int		count;
	char	*w;

	w = NULL;
	count = 0;
	if (*s == LABEL_CHAR)
		s = print_label(s, q, t, 2);
	else
	{
		while (s[count] != SEPARATOR_CHAR &&
			!(ft_isspace(s[count])) && s[count])
			count++;
		w = ft_strsub(s, 0, (size_t)count);
		q = (unsigned int)ft_atoi(w);
		q = swap(q, IND_SIZE);
		write(g_asm.fd, &q, IND_SIZE);
	}
	free(w);
	return (s);
}

char	*write_register(char *str, int count, unsigned int q)
{
	char *w;

	str++;
	while (str[count] != SEPARATOR_CHAR &&
		!(ft_isspace(str[count])) && str[count])
		count++;
	w = ft_strsub(str, 0, (size_t)count);
	q = (unsigned int)ft_atoi(w);
	free(w);
	write(g_asm.fd, &q, REG_SIZE);
	return (str);
}

int		first_second_arg_codage(t_labels *t, int p, int number)
{
	int	q;

	q = 0;
	if (number == 1)
	{
		if (t->str[p] == DIRECT_CHAR)
			q = 0x80;
		else if (t->str[p] == 'r')
			q = 0x40;
		else if (t->str[p] == LABEL_CHAR || t->str[p] == '-' ||
				ft_isdigit(t->str[p]))
			q = 0xc0;
	}
	else if (number == 2)
	{
		if (t->str[p] == DIRECT_CHAR)
			q = 0x20;
		else if (t->str[p] == 'r')
			q = 0x10;
		else if (t->str[p] == LABEL_CHAR || t->str[p] == '-' ||
				ft_isdigit(t->str[p]))
			q = 0x30;
	}
	return (q);
}

int		third_arg_codage(t_labels *t, int p)
{
	int q;

	q = 0;
	if (t->str[p] == DIRECT_CHAR)
		q = 0x8;
	else if (t->str[p] == 'r')
		q = 0x4;
	else if (t->str[p] == LABEL_CHAR || t->str[p] == '-' ||
			ft_isdigit(t->str[p]))
		q = 0xc;
	return (q);
}
