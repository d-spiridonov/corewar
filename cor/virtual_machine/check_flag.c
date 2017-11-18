/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:03:37 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/24 11:10:34 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	n(char **av, int *i, t_skrr *skrr, int ac)
{
	*i + 1 < ac ? skrr->flag_n[skrr->cnt_n] = (int)ft_atoi(av[*i + 1]) : 0;
	skrr->flag_n[skrr->cnt_n] < 0 || !av[*i + 1] ? argv_error(0, 0, 8) : 0;
	skrr->flag_n[skrr->cnt_n] != 0 ? (*i) += 2 : argv_error(0, 0, 8);
}

void	dump(char **av, int *i, t_skrr *skrr)
{
	int lev_av;
	int cnt_av;

	(!av[*i + 1]) || (av[*i + 1] && !ft_isdigit(av[*i + 1][0])) ?
	argv_error(skrr, av, 7) : 0;
	skrr->flag_dump = (int)ft_atoi(av[*i + 1]);
	lev_av = (int)ft_strlen(av[*i + 1]);
	cnt_av = len_value(skrr->flag_dump);
	cnt_av == 0 ? cnt_av++ : 0;
	lev_av > cnt_av ? argv_error(skrr, av, 7) : 0;
	(*i) += 2;
}

void	a(char **av, int *i, t_skrr *skrr)
{
	av[*i + 1] && ft_isdigit(av[*i + 1][0]) ? usage_e() : 0;
	skrr->flag_a = 1;
	(*i)++;
}
