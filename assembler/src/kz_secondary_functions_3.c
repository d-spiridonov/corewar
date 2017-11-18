/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_secondary_functions_3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 19:32:45 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:40:36 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void			count_par_b(short numder_arg, t_labels *tmp, int i, int p)
{
	(g_asm.label > 0) ? p += g_asm.label : 0;
	p += ft_strlen(g_tab[i].name);
	while (ft_isspace(tmp->str[p]))
		p++;
	while (numder_arg > 0)
	{
		if (tmp->str[p] == DIRECT_CHAR)
			g_asm.prog_size += (g_tab[i].dir_size == 1) ? DIR_SIZE :
							(DIR_SIZE + 2);
		else if (tmp->str[p] == 'r')
			g_asm.prog_size += REG_SIZE;
		else if (tmp->str[p] == LABEL_CHAR || tmp->str[p] == '-' ||
				ft_isdigit(tmp->str[p]))
			g_asm.prog_size += IND_SIZE;
		p = leaf_p(tmp, p);
		numder_arg--;
	}
	g_asm.prog_size += (g_tab[i].codage == 1) ? 2 : 1;
}

int				count_par_fn(short numder_arg, t_labels *tmp, int i, int p)
{
	int size;

	size = 0;
	(g_asm.label > 0) ? p += g_asm.label : 0;
	p += ft_strlen(g_tab[i].name);
	while (ft_isspace(tmp->str[p]))
		p++;
	while (numder_arg > 0)
	{
		if (tmp->str[p] == DIRECT_CHAR)
			size += (g_tab[i].dir_size == 1) ? DIR_SIZE : (DIR_SIZE + 2);
		else if (tmp->str[p] == 'r')
			size += REG_SIZE;
		else if (tmp->str[p] == LABEL_CHAR || tmp->str[p] == '-' ||
				ft_isdigit(tmp->str[p]))
			size += IND_SIZE;
		p = leaf_p(tmp, p);
		numder_arg--;
	}
	size += (g_tab[i].codage == 1) ? 2 : 1;
	return (size);
}

unsigned int	convert(unsigned int s)
{
	unsigned char	*d;

	d = (unsigned char *)&s;
	s = ((unsigned int)d[0] << 24 | (unsigned int)d[1] << 16 |
			(unsigned int)d[2] << 8 | (unsigned int)d[3]);
	return (s);
}

unsigned int	swap(unsigned int s, int dir_size)
{
	if (dir_size == 4)
		s = ((s << 24) & 0xff000000) | ((s << 8) & 0xff0000) | \
		((s >> 8) & 0xff00) | ((s >> 24) & 0x000000ff);
	else if (dir_size == 2)
		s = (((s << 8) & 0xff00) | ((s >> 8) & 0xff));
	return (s);
}

int				leaf_p(t_labels *tmp, int p)
{
	while (tmp->str[p] != SEPARATOR_CHAR &&
			!(ft_isspace(tmp->str[p])) && tmp->str[p])
		p++;
	while (tmp->str[p] == SEPARATOR_CHAR ||
			ft_isspace(tmp->str[p]))
		p++;
	return (p);
}
