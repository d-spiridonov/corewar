/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_in_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:11:09 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/24 12:48:46 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int				maybe_flag(char **av, int *i, t_skrr *skrr, int ac)
{
	skrr->flag_n == NULL ? skrr->flag_n = ft_intmalloc(MAX_PLAYERS) : 0;
	if (!ft_strcmp(av[*i], "-n"))
	{
		n(av, i, skrr, ac);
		skrr->cnt_n++;
		return (1);
	}
	else if (!ft_strcmp(av[*i], "-v"))
	{
		skrr->flag_v = 1;
		(*i)++;
		return (1);
	}
	else if (!ft_strcmp(av[*i], "-dump"))
	{
		dump(av, i, skrr);
		return (1);
	}
	else if (!ft_strcmp(av[*i], "-a"))
	{
		a(av, i, skrr);
		return (1);
	}
	return (0);
}

void			find_player(char **av, int *i, t_skrr *skrr)
{
	chk_open(skrr, av, *i, 1);
	push_chmp(&skrr->chmp, skrr);
	just_read(skrr, av[*i], skrr->chmp);
	skrr->max_player++;
	skrr->chmp->ac = *i;
	(*i)++;
}

void			parsing_arg(t_skrr *skrr, char **av, int ac)
{
	int i;

	i = 1;
	header_errors();
	while (i < ac)
	{
		while (maybe_flag(av, &i, skrr, ac))
			if (i == ac)
			{
				!ft_strcmp(av[(i - 1)], "-v") || !ft_strcmp(av[(i - 1)], "-a")
					|| !ft_strcmp(av[(i - 2)], "-dump") ? 0 : usage_e();
				break ;
			}
		if (i != ac)
			find_player(av, &i, skrr);
		else
			break ;
	}
	i == ac && skrr->max_player == 0 ? usage_e() : 0;
	skrr->max_player > MAX_PLAYERS ? chk_open(0, 0, 0, 0) : 0;
	flag_n(skrr);
	prog_commands(skrr, av, skrr->chmp);
	init_flag(skrr);
}

unsigned int	zero_reg(t_skrr *skrr)
{
	static int	nbr;
	static int	tmp;
	int			c;

	c = -1;
	while (++c < skrr->max_player)
	{
		if (skrr->flag_n[c] == tmp)
			tmp++;
	}
	if (skrr->flag_n[nbr] == 0)
	{
		skrr->flag_n[nbr] = tmp;
		nbr++;
		c = tmp;
		tmp++;
		return (unsigned int)(c * -1);
	}
	else
	{
		c = nbr;
		nbr++;
		return ((unsigned int)(skrr->flag_n[c] * -1));
	}
}

void			flag_n(t_skrr *skrr)
{
	int		i;
	t_proc	*tmp;

	i = 0;
	skrr->init_id = 1;
	tmp = skrr->process;
	skrr->cnt_n > skrr->max_player ? argv_error(skrr, 0, 5) : 0;
	while (i < skrr->max_player)
	{
		skrr->flag_n[i] > skrr->max_player ? argv_error(skrr, 0, 4) : 0;
		while (tmp->id != skrr->init_id * (-1))
			tmp = tmp->next;
		tmp->registry[0] = zero_reg(skrr);
		i++;
		skrr->init_id++;
		tmp = skrr->process;
	}
	i = -1;
	while (++i < skrr->max_player)
		ft_intc(skrr->flag_n, skrr->flag_n[i], skrr->max_player) > 1 ?
		argv_error(skrr, 0, 6) : 0;
	free(skrr->flag_n);
}
