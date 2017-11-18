/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_highlighting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:56:32 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/10/21 20:56:57 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	del_highl(t_skrr *skrr, int id)
{
	t_highl *current;
	t_highl *prev;

	prev = NULL;
	current = skrr->vis->highl;
	if (current->id == id)
	{
		skrr->vis->highl = current->next;
		free(current);
		return ;
	}
	while (current != NULL)
	{
		if (current->id == id)
		{
			prev->next = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	add_to_highl(t_skrr *skrr, int id)
{
	t_highl *newnode;

	newnode = (t_highl*)malloc(sizeof(t_highl));
	newnode->id = id;
	newnode->cycle = g_cycles + 50;
	newnode->next = skrr->vis->highl;
	skrr->vis->highl = newnode;
}

int		highlight(t_skrr *skrr, int id)
{
	t_highl *tmp;

	tmp = skrr->vis->highl;
	while (tmp != NULL)
	{
		if (tmp->id == id)
		{
			if (tmp->cycle <= g_cycles)
			{
				skrr->mapid[skrr->i] /= 10;
				del_highl(skrr, id);
				wattrset(skrr->vis->code, COLOR_PAIR(skrr->mapid[skrr->i]));
				return (0);
			}
			wattrset(skrr->vis->code, COLOR_PAIR(skrr->mapid[skrr->i] / 10));
			wattron(skrr->vis->code, A_BOLD);
			return (0);
		}
		tmp = tmp->next;
	}
	wattrset(skrr->vis->code, COLOR_PAIR(skrr->mapid[skrr->i] / 10));
	wattron(skrr->vis->code, A_BOLD);
	add_to_highl(skrr, id);
	return (1);
}
