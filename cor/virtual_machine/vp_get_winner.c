/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:31:42 by vpoltave          #+#    #+#             */
/*   Updated: 2017/10/26 11:34:23 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

char	*name_winner(t_chmp *chmp, int id)
{
	t_chmp *tmp;

	tmp = chmp;
	while (tmp)
	{
		if (tmp->id == id)
			return (ft_strdup(tmp->header.prog_name));
		tmp = tmp->next;
	}
	g_cycles++;
	return (0);
}

void	pt_winner(t_skrr *skrr, t_chmp *chmp, int best_player)
{
	char *name;

	if (skrr->flag_v == 1)
		printwinner(skrr, name = name_winner(chmp, best_player), best_player);
	else
		ft_printf("Contestant %d, " GRN"\"%s\""RESET ", has won !\n",
				best_player * (-1), name = name_winner(chmp, best_player));
	free(name);
}

void	winner(t_chmp *chmp, t_skrr *skrr, long best_cycle, int best_player)
{
	t_chmp	*chmp_tmp;

	chmp_tmp = chmp;
	chmp_tmp->next != NULL ? chmp_tmp = chmp_tmp->next : 0;
	while (chmp_tmp)
	{
		if (best_cycle <= chmp_tmp->last_live)
		{
			if (best_cycle == chmp_tmp->last_live)
				best_player =
					best_player < chmp_tmp->id ? chmp_tmp->id : best_player;
			else
			{
				best_player = chmp_tmp->id;
				best_cycle = chmp_tmp->last_live;
			}
		}
		chmp_tmp = chmp_tmp->next;
	}
	pt_winner(skrr, chmp, best_player);
	exit(1);
}
