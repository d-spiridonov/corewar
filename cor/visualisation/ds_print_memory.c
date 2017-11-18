/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:58:46 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/10/21 20:59:58 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		findprocess(t_skrr *skrr, int pc)
{
	t_proc	*tmp;

	tmp = skrr->process;
	while (tmp != NULL)
	{
		if (tmp->pc == pc)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	print_carriage(t_skrr *skrr, int y, int x)
{
	if (skrr->mapid[skrr->i] == 0)
		wattrset(skrr->vis->code, COLOR_PAIR(29) | A_NORMAL);
	else
		wattrset(skrr->vis->code, COLOR_PAIR(skrr->mapid[skrr->i]));
	if (skrr->mapid[skrr->i] > 9)
		highlight(skrr, skrr->i);
	wattron(skrr->vis->code, A_REVERSE);
	mvwprintw(skrr->vis->code, y, x, "%hh.2x", skrr->map[skrr->i++]);
	wattrset(skrr->vis->code, COLOR_PAIR(0) | A_NORMAL);
	mvwprintw(skrr->vis->code, y, x + 2, " ");
}

void	print_regular_cells(t_skrr *skrr, int y, int x)
{
	if (skrr->mapid[skrr->i] == 0)
	{
		wattrset(skrr->vis->code, COLOR_PAIR(27));
		wattron(skrr->vis->code, A_BOLD);
	}
	else
	{
		wattrset(skrr->vis->code, COLOR_PAIR(skrr->mapid[skrr->i]));
		wattroff(skrr->vis->code, A_BOLD);
		if (skrr->mapid[skrr->i] > 9)
			highlight(skrr, skrr->i);
	}
	mvwprintw(skrr->vis->code, y, x, "%hh.2x ", skrr->map[skrr->i++]);
}

void	printmem(t_skrr *skrr)
{
	int y;
	int x;
	int i;

	x = 3;
	y = 2;
	skrr->i = 0;
	i = 0;
	while (skrr->i < MEM_SIZE)
	{
		while (i++ < 64)
		{
			if (i_am_alive(skrr) == 1)
				mvwprintw(skrr->vis->code, y, x, "%hh.2x", \
						skrr->map[skrr->i++]);
			else if (findprocess(skrr, skrr->i) == 1)
				print_carriage(skrr, y, x);
			else
				print_regular_cells(skrr, y, x);
			x = x + 3;
		}
		y++;
		x = 3;
		i = 0;
	}
}
