/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_printdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 21:01:40 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/10/21 21:01:43 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		print_champs_data(t_skrr *skrr)
{
	mvwaddstr(skrr->vis->menu, 11, 3, "Player -1 :");
	mvwaddstr(skrr->vis->menu, 12, 5, "Last live :");
	mvwaddstr(skrr->vis->menu, 13, 5, "Lives in current period :");
	if (skrr->max_player > 1)
	{
		mvwprintw(skrr->vis->menu, 15, 3, "Player -2 :");
		mvwaddstr(skrr->vis->menu, 16, 5, "Last live :");
		mvwaddstr(skrr->vis->menu, 17, 5, "Lives in current period :");
	}
	if (skrr->max_player > 2)
	{
		mvwprintw(skrr->vis->menu, 19, 3, "Player -3 :");
		mvwaddstr(skrr->vis->menu, 20, 5, "Last live :");
		mvwaddstr(skrr->vis->menu, 21, 5, "Lives in current period :");
	}
	if (skrr->max_player > 3)
	{
		mvwprintw(skrr->vis->menu, 23, 3, "Player -4 :");
		mvwaddstr(skrr->vis->menu, 24, 5, "Last live :");
		mvwaddstr(skrr->vis->menu, 25, 5, "Lives in current period :");
	}
	return (0);
}

void	menufields(WINDOW *menu, t_skrr *skrr)
{
	int y;

	y = (skrr->max_player * 4);
	wattron(menu, COLOR_PAIR(26) | A_BOLD);
	mvwaddstr(menu, 4, 3, "Speed :");
	mvwaddstr(menu, 7, 3, "Cycle :");
	mvwaddstr(menu, 9, 3, "Processes :");
	print_champs_data(skrr);
	mvwaddstr(menu, 11 + y, 3, "Live breakdown for current period :");
	wattron(menu, COLOR_PAIR(26));
	mvwaddstr(menu, 14 + y, 3, "Live breakdown for last period :");
	if ((int)g_cycles < skrr->cycle_to_die)
	{
		wattron(skrr->vis->menu, COLOR_PAIR(27) | A_BOLD);
		mvwaddstr(menu, 15 + y, 3, "[-----------------------------------------"\
		"---------]");
	}
	wattron(menu, COLOR_PAIR(26));
	mvwaddstr(menu, 17 + y, 3, "CYCLE_TO_DIE :");
	mvwaddstr(menu, 19 + y, 3, "CYCLE_DELTA :");
	mvwaddstr(menu, 21 + y, 3, "NBR_LIVE :");
	mvwaddstr(menu, 23 + y, 3, "MAX_CHECKS :");
}

void	printmargins(WINDOW *code, WINDOW *menu, int width, int height)
{
	int i;

	i = 0;
	wattron(code, COLOR_PAIR(25));
	wattron(menu, COLOR_PAIR(25));
	while (i < height)
	{
		mvwaddch(code, i, 0, ' ' | A_REVERSE);
		mvwaddch(menu, i, 0, ' ' | A_REVERSE);
		mvwaddch(menu, i++, 57, ' ' | A_REVERSE);
	}
	i = 0;
	while (i < width - 57)
	{
		mvwaddch(code, 0, i, ' ' | A_REVERSE);
		mvwaddch(code, height - 1, i++, ' ' | A_REVERSE);
	}
	i = 0;
	while (i < 57)
	{
		mvwaddch(menu, 0, i, ' ' | A_REVERSE);
		mvwaddch(menu, 67, i, ' ' | A_REVERSE);
		mvwaddch(menu, 55, i++, ' ' | A_REVERSE);
	}
}

void	print_add_champs(t_skrr *skrr, int y, int id)
{
	wattron(skrr->vis->menu, COLOR_PAIR(champ_color(skrr, id)));
	mvwprintw(skrr->vis->menu, y, 15, "%s", find_progname(skrr, id));
	wattron(skrr->vis->menu, COLOR_PAIR(26));
	mvwprintw(skrr->vis->menu, y + 1, 37, "%ld", find_last_live(skrr, id));
	mvwprintw(skrr->vis->menu, y + 2, 37, "%d      ", \
	find_live_count(skrr, id));
}

void	printdata(WINDOW *menu, t_skrr *skrr)
{
	mvwaddstr(menu, 2, 3, "** RUNNING **");
	mvwprintw(menu, 9, 15, "%d", skrr->process_count);
	mvwprintw(menu, 7, 11, "%d", g_cycles);
	wattron(menu, COLOR_PAIR(champ_color(skrr, -1)));
	mvwprintw(menu, 11, 15, "%s", find_progname(skrr, -1));
	wattron(menu, COLOR_PAIR(26));
	mvwprintw(menu, 12, 37, "%ld", find_last_live(skrr, -1));
	mvwprintw(menu, 13, 37, "%d      ", find_live_count(skrr, -1));
	if (skrr->max_player > 1)
		print_add_champs(skrr, 15, -2);
	if (skrr->max_player > 2)
		print_add_champs(skrr, 19, -3);
	if (skrr->max_player > 3)
		print_add_champs(skrr, 23, -4);
	breakdown_current(skrr, 12);
	if (g_ctd + 1 == skrr->cycle_to_die)
		breakdown_current(skrr, 15);
	wattron(menu, COLOR_PAIR(26));
	mvwprintw(menu, 17 + skrr->max_player * 4, 18, "%d ", skrr->cycle_to_die);
	mvwprintw(menu, 19 + skrr->max_player * 4, 17, "%d ", CYCLE_DELTA);
	mvwprintw(menu, 21 + skrr->max_player * 4, 14, "%d ", NBR_LIVE);
	mvwprintw(menu, 23 + skrr->max_player * 4, 16, "%d ", skrr->max_checks);
}
