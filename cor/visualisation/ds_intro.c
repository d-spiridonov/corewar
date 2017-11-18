/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 23:09:45 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/10/23 23:21:36 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	intro_add(t_skrr *skrr)
{
	mvwprintw(skrr->vis->code, 29, 55, " \\______| \\______/  | _| `._____||"\
	"_______|   \\__/  \\__/ /__/     \\__\\ | _| `._____|");
	wrefresh(skrr->vis->code);
	napms(200);
	mvwprintw(skrr->vis->code, 30, 70, "by kzakharc, yzakharc, vpoltave, dspy"\
	"rydo");
	wrefresh(skrr->vis->code);
	napms(3000);
}

void	intro(t_skrr *skrr)
{
	wattron(skrr->vis->code, COLOR_PAIR(25));
	mvwprintw(skrr->vis->code, 24, 55, "  ______   ______   .______       ___"\
	"________    __    ____  ___      .______      ");
	wrefresh(skrr->vis->code);
	napms(200);
	mvwprintw(skrr->vis->code, 25, 55, " /      | /  __  \\  |   _  \\     | "\
	"  ____\\   \\  /  \\  /   / /   \\     |   _  \\     ");
	wrefresh(skrr->vis->code);
	napms(200);
	mvwprintw(skrr->vis->code, 26, 55, "|  ,----'|  |  |  | |  |_)  |    |  |"\
	"__   \\   \\/    \\/   / /  ^  \\    |  |_)  | ");
	wrefresh(skrr->vis->code);
	napms(200);
	mvwprintw(skrr->vis->code, 27, 55, "|  |     |  |  |  | |      /     |  "\
	" __|   \\            / /  /_\\  \\   |      /     ");
	wrefresh(skrr->vis->code);
	napms(200);
	mvwprintw(skrr->vis->code, 28, 55, "|  `----.|  `--'  | |  |\\  \\----.|"\
	"  |____   \\    /\\    / /  _____  \\  |  |\\  \\----.");
	wrefresh(skrr->vis->code);
	napms(200);
	intro_add(skrr);
}
