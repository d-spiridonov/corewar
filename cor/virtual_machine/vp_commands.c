/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:31:21 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/10 17:31:23 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void			correct_id(t_skrr *skrr)
{
	t_chmp *chmp_tmp;
	t_proc *proc_tmp;

	chmp_tmp = skrr->chmp;
	proc_tmp = skrr->process;
	while (proc_tmp)
	{
		chmp_tmp->id = proc_tmp->registry[0];
		proc_tmp->id = proc_tmp->registry[0];
		chmp_tmp = chmp_tmp->next;
		proc_tmp = proc_tmp->next;
	}
}

void			prog_commands(t_skrr *skrr, char **av, t_chmp *chmp)
{
	unsigned char	*line;
	t_chmp			*champ_tmp;
	t_proc			*proc_tmp;

	champ_tmp = chmp;
	proc_tmp = skrr->process;
	init_map(skrr);
	correct_id(skrr);
	while (champ_tmp && proc_tmp)
	{
		proc_tmp->tmp_pc =
				player_position(proc_tmp->registry[0], skrr, champ_tmp);
		line = (unsigned char*)ft_strnew(champ_tmp->header.prog_size);
		chk_size(skrr, av[champ_tmp->ac], line, champ_tmp);
		skrr->i = 0;
		while (read(champ_tmp->fd, &line[skrr->i], 1))
			skrr->i++;
		unsafe_copy(skrr, line, champ_tmp);
		champ_tmp = champ_tmp->next;
		proc_tmp = proc_tmp->next;
		free(line);
	}
}

void			unsafe_copy(t_skrr *skrr, unsigned char *line, t_chmp *chmp)
{
	int pos;

	pos = chmp->player_pos;
	if (line == NULL)
		exit(1);
	while (skrr->i-- > 0)
	{
		skrr->mapid[pos] = (unsigned char)((chmp->id * -1));
		skrr->map[pos++] = *line++;
	}
}

void			init_map(t_skrr *skrr)
{
	skrr->i = 0;
	while (skrr->i < MEM_SIZE)
	{
		skrr->mapid[skrr->i] = 0;
		skrr->map[skrr->i++] = 0;
	}
}

unsigned int	player_position(int nbr, t_skrr *skrr, t_chmp *chmp)
{
	unsigned int tmp;

	tmp = (unsigned int)(MEM_SIZE / skrr->max_player);
	chmp->player_pos = (nbr == -1) ? 0 : tmp * (-1 * nbr - 1);
	return (chmp->player_pos);
}
