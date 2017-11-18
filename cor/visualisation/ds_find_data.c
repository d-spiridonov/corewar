/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_find_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:56:01 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/10/21 20:56:19 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		champ_color(t_skrr *skrr, int id)
{
	t_chmp *tmp;

	tmp = skrr->chmp;
	while (tmp != NULL)
	{
		if (tmp->id == id)
			return (tmp->id * -1);
		tmp = tmp->next;
	}
	return (0);
}

int		find_live_count(t_skrr *skrr, int id)
{
	t_chmp *tmp;

	tmp = skrr->chmp;
	while (tmp != NULL)
	{
		if (tmp->id == id)
			return (tmp->live_count);
		tmp = tmp->next;
	}
	return (0);
}

long	find_last_live(t_skrr *skrr, int id)
{
	t_chmp *tmp;

	tmp = skrr->chmp;
	while (tmp != NULL)
	{
		if (tmp->id == id)
			return (tmp->last_live);
		tmp = tmp->next;
	}
	return (0);
}

char	*find_progname(t_skrr *skrr, int id)
{
	t_chmp *tmp;

	tmp = skrr->chmp;
	while (tmp != NULL)
	{
		if (tmp->id == id)
			return (tmp->header.prog_name);
		tmp = tmp->next;
	}
	return (NULL);
}
