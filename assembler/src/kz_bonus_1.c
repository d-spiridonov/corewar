/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_bonus_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:48:46 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:33:24 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void			print_details(t_labels *tmp, int i, int p, int c)
{
	char	*s;
	char	*w;

	ft_printf("\n");
	count_write_codage_opcode_a(tmp, i);
	s = ft_strsub(tmp->str, (unsigned int)c, (ft_strlen(tmp->str) - c));
	w = s;
	while (p < g_tab[i].numb_of_arg)
	{
		g_asm.li = 0;
		g_asm.ll = 0;
		if (*s == 'r')
		{
			s++;
			ft_printf("%-18d", ft_atoi(s));
		}
		else if (*s == DIRECT_CHAR)
			s = write_dir_out(s, tmp, 0, i);
		else if (*s == LABEL_CHAR || *s == '-' || ft_isdigit(*s))
			s = wrt_indir_out(s, tmp, 0);
		s = leaf_str(s);
		p++;
	}
	free(w);
	print_standart_info(tmp, i, c, 0);
}

void			print_standart_info(t_labels *tmp, int i, int c, int p)
{
	char	*s;
	char	*w;

	ft_printf("\n");
	count_write_codage_opcode_a(tmp, i);
	s = ft_strsub(tmp->str, (unsigned int)c, (ft_strlen(tmp->str) - c));
	w = s;
	while (p < g_tab[i].numb_of_arg)
	{
		g_asm.li = 0;
		g_asm.ll = 0;
		if (*s == 'r')
		{
			s++;
			ft_printf("%-18d", ft_atoi(s));
		}
		else if (*s == DIRECT_CHAR)
			s = w_dir_out_stn(s, tmp, 0);
		else if (*s == LABEL_CHAR || *s == '-' || ft_isdigit(*s))
			s = w_indir_out_stn(s, tmp, 0);
		s = leaf_str(s);
		p++;
	}
	free(w);
	ft_printf("\n\n");
}

char			*wrt_indir_out(char *s, t_labels *t, unsigned int q)
{
	unsigned char	dir;
	int				shift;

	shift = 8;
	if (*s == LABEL_CHAR)
	{
		s++;
		g_asm.p = 0;
		find_label_to_writ(s, t, 0, 0);
		fnd_l_for_ins_a(t, g_file, g_asm.last_det, 1);
		q = (unsigned int)(find_size_of_prog_here(g_asm.ll - 1, g_file) -
							find_size_of_prog_here(g_asm.li - 1, g_file));
	}
	else
		q = (unsigned int)ft_atoi(s);
	while (shift >= 0)
	{
		dir = magic(shift, q);
		ft_printf("%-4d", dir);
		shift -= 8;
	}
	ft_printf("\t\t ");
	return (s);
}

char			*write_dir_out(char *s, t_labels *t, unsigned int q, int i)
{
	unsigned char	dir;
	int				shift;

	s++;
	shift = (g_tab[i].dir_size == 0) ? 24 : 8;
	if (*s == LABEL_CHAR)
	{
		s++;
		g_asm.p = 0;
		find_label_to_writ(s, t, 0, 0);
		fnd_l_for_ins_a(t, g_file, g_asm.last_det, 1);
		q = (unsigned int)(find_size_of_prog_here(g_asm.ll - 1, g_file) -
							find_size_of_prog_here(g_asm.li - 1, g_file));
	}
	else
		q = (unsigned int)ft_atoi(s);
	while (shift >= 0)
	{
		dir = magic(shift, q);
		ft_printf("%-4d", dir);
		shift -= 8;
	}
	(g_tab[i].dir_size == 0) ? ft_printf("  ") : ft_printf("\t\t ");
	return (s);
}

unsigned char	magic(int shift, unsigned int m)
{
	unsigned char magic;

	magic = 0;
	(shift == 24) ? (magic = (unsigned char)(m >> shift)) : 0;
	(shift == 16) ? (magic = (unsigned char)(m >> shift)) : 0;
	(shift == 8) ? (magic = (unsigned char)(m >> shift)) : 0;
	(shift == 0) ? (magic = (unsigned char)m) : 0;
	return (magic);
}
