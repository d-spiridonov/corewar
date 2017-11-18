/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:19:52 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/26 11:36:35 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void			print_map(t_skrr *skrr)
{
	int line;

	line = 0;
	skrr->i = 0;
	ft_printf("0x0000 : ");
	while (skrr->i < MEM_SIZE)
	{
		ft_printf("%hh.2x ", skrr->map[skrr->i]);
		if ((skrr->i + 1) % 64 == 0 && skrr->i != 4095)
			ft_printf("\n%06#x : ", line += 64);
		skrr->i++;
	}
	write(1, "\n", 1);
}

static void		ft_output(t_chmp *champ_tmp)
{
	ft_printf("* Player %d, ", champ_tmp->id * (-1));
	ft_printf("Name:" GRN" \"%s\""RESET, champ_tmp->header.prog_name);
	ft_printf(", weighing" GRN" %u "RESET "bytes, ",
			champ_tmp->header.prog_size);
	ft_printf("comment:" GRN" \"%s\"\n"RESET,
			champ_tmp->header.comment);
}

void			print_info(t_chmp *chmp)
{
	t_chmp	*champ_tmp;
	int		cnt;
	int		tmp;

	cnt = -1;
	champ_tmp = chmp;
	ft_printf("Introducing contestants...\n");
	while (champ_tmp)
	{
		tmp = cnt;
		if (champ_tmp->id == cnt)
		{
			ft_output(champ_tmp);
			cnt--;
			champ_tmp = chmp;
		}
		tmp == cnt ? champ_tmp = champ_tmp->next : 0;
	}
}

void			dump_print(t_skrr *skrr)
{
	print_map(skrr);
	exit(0);
}
