/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_bonus_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:16:26 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:33:42 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	count_write_codage_opcode_a(t_labels *tmp, int i)
{
	int		codage;

	if (g_tab[i].codage == 1)
	{
		codage = write_codage(tmp, i, 0, 0);
		ft_printf("\t\t   %-4d%-6d", g_tab[i].opcode, codage);
	}
	else
		ft_printf("\t\t   %-4d      ", g_tab[i].opcode);
}

int		fnd_l_for_ins_a(t_labels *tmp, t_file *t, int last_l, int n)
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
	if ((last_l != 0) && (last_l >= g_asm.li))
	{
		while (fn && ((last_l >= g_asm.li) ||
					ft_strncmp(tmp->str, fn->str, ft_strlen(tmp->str))))
		{
			fn = fn->next;
			g_asm.li++;
		}
	}
	n == 0 ? g_asm.last_mas = g_asm.li : 0;
	n == 1 ? g_asm.last_det = g_asm.li : 0;
	n == 2 ? g_asm.last_stn = g_asm.li : 0;
	return (g_asm.li);
}

char	*w_dir_out_stn(char *s, t_labels *t, unsigned int q)
{
	s++;
	if (*s == LABEL_CHAR)
	{
		s++;
		g_asm.p = 0;
		find_label_to_writ(s, t, 0, 0);
		fnd_l_for_ins_a(t, g_file, g_asm.last_stn, 2);
		q = (unsigned int)(find_size_of_prog_here(g_asm.ll - 1, g_file) -
							find_size_of_prog_here(g_asm.li - 1, g_file));
	}
	else
		q = (unsigned int)ft_atoi(s);
	ft_printf("%-18d", q);
	return (s);
}

char	*w_indir_out_stn(char *s, t_labels *t, unsigned int q)
{
	if (*s == LABEL_CHAR)
	{
		s++;
		g_asm.p = 0;
		find_label_to_writ(s, t, 0, 0);
		fnd_l_for_ins_a(t, g_file, g_asm.last_stn, 2);
		q = (unsigned int)(find_size_of_prog_here(g_asm.ll - 1, g_file) -
							find_size_of_prog_here(g_asm.li - 1, g_file));
	}
	else
		q = (unsigned int)ft_atoi(s);
	ft_printf("%-4d\t\t", q);
	return (s);
}
