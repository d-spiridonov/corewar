/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:57:09 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/10/21 20:58:31 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	del_live(t_skrr *skrr)
{
	t_live	*current;
	t_live	*prev;

	prev = NULL;
	current = skrr->vis->live;
	if (current->id == (int)skrr->i)
	{
		skrr->vis->live = current->next;
		free(current);
		return ;
	}
	while (current != NULL)
	{
		if (current->id == (int)skrr->i)
		{
			prev->next = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	add_to_live(t_skrr *skrr, int proctmp)
{
	t_live *newnode;

	newnode = (t_live*)malloc(sizeof(t_live));
	newnode->id = skrr->i;
	newnode->cycle = g_cycles + 50;
	newnode->colorid = (proctmp > 9) ? proctmp / 10 + 10 : proctmp + 10;
	newnode->next = skrr->vis->live;
	skrr->vis->live = newnode;
}

int		find_live(t_skrr *skrr)
{
	t_live *livetmp;

	livetmp = skrr->vis->live;
	while (livetmp != NULL)
	{
		if (livetmp->id == (int)skrr->i)
		{
			if (livetmp->cycle <= g_cycles || skrr->map[skrr->i] != 01)
			{
				del_live(skrr);
				wattrset(skrr->vis->code,
				COLOR_PAIR(livetmp->colorid) | A_BOLD);
				return (1);
			}
			wattrset(skrr->vis->code,
			COLOR_PAIR(livetmp->colorid) | A_BOLD);
			return (1);
		}
		livetmp = livetmp->next;
	}
	return (0);
}

int		i_am_alive(t_skrr *skrr)
{
	t_proc *proctmp;

	proctmp = skrr->process;
	if (find_live(skrr) == 1)
		return (1);
	while (proctmp != NULL)
	{
		if (proctmp->live_pc == (int)skrr->i && proctmp->live_color == 1 \
				&& skrr->map[skrr->i] == 01)
		{
			add_to_live(skrr, skrr->mapid[skrr->i]);
			wattrset(skrr->vis->code,
				COLOR_PAIR(skrr->vis->live->colorid) | A_BOLD);
			proctmp->live_color = 0;
			return (1);
		}
		proctmp = proctmp->next;
	}
	return (0);
}
