/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_output_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:31:58 by vpoltave          #+#    #+#             */
/*   Updated: 2017/10/24 21:30:57 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	argv_error(t_skrr *skrr, char **argv, int flag)
{
	if (flag == 2)
		ft_printf("Error: File"RED" %s "RESET"has an invalid header\n", *argv);
	else if (flag == 3)
		ft_printf("Error:"RED" %s "RESET"is a directory\n", *argv);
	else if (flag == 4)
		ft_printf(""RED"Error:"RESET" Please enter a player number from 1 to"
				" %i\n", skrr->max_player);
	else if (flag == 5)
		ft_printf(""RED"Error:"RESET" You typed too many flags "GRN"\"-n\""
				""RESET"\n");
	else if (flag == 6)
		ft_printf(""RED"Error:"RESET" You typed wrong player number\n");
	else if (flag == 7)
		ft_printf(""RED"Error:"RESET" Enter the correct number of the cycle\n");
	else if (flag == 8)
		ft_printf(""RED"Error:"RESET" Wrong player number\n");
	(flag != 1) ? exit(flag) : 0;
}

void	chk_open(t_skrr *skrr, char **argv, int i, int flag)
{
	if (flag == 0)
	{
		ft_printf("Too many champions! (Max %d)\n", MAX_PLAYERS);
		exit(0);
	}
	else if (flag == 1)
	{
		skrr->fd = open(argv[i], O_RDONLY);
		if (skrr->fd < 0)
		{
			ft_printf("Can't read source file"RED" %s"RESET"\n", argv[i]);
			close(skrr->fd) < 0 ? exit(0) : 0;
			exit(flag);
		}
	}
}

void	header_errors(void)
{
	if ((REG_SIZE != 1) || (DIR_SIZE != 2) || ((IND_SIZE != 2)))
	{
		(REG_SIZE != 1) ? ft_printf(MAG"Warning:"RESET " REG_SIZE != 1\n") : 0;
		(DIR_SIZE != 2) ? ft_printf(MAG"Warning:"RESET " DIR_SIZE != 2\n") : 0;
		(IND_SIZE != 2) ? ft_printf(MAG"Warning:"RESET " IND_SIZE != 2\n") : 0;
		exit(1);
	}
	else if ((REG_CODE != 1) || (DIR_CODE != 2) || (IND_CODE != 3))
	{
		(REG_CODE != 1) ? ft_printf(MAG"Warning:"RESET " REG_CODE != 1\n") : 0;
		(DIR_CODE != 2) ? ft_printf(MAG"Warning:"RESET " DIR_CODE != 2\n") : 0;
		(IND_CODE != 3) ? ft_printf(MAG"Warning:"RESET " IND_CODE != 3\n") : 0;
		exit(2);
	}
	else if ((MEM_SIZE != 4096) || (T_REG != 1) || (T_DIR != 2) || (T_IND != 4))
	{
		(MEM_SIZE != 4096) ?
			ft_printf(MAG"Warning:"RESET " MEM_SIZE != 4096\n") : 0;
		(T_REG != 1) ? ft_printf(MAG"Warning:"RESET " T_REG != 1\n") : 0;
		(T_DIR != 2) ? ft_printf(MAG"Warning:"RESET " T_DIR != 2\n") : 0;
		(T_IND != 4) ? ft_printf(MAG"Warning:"RESET " T_IND != 4\n") : 0;
		exit(3);
	}
	header_errors_2();
}

void	header_errors_2(void)
{
	if ((PROG_NAME_LENGTH != 128) || (COMMENT_LENGTH != 2048))
	{
		(PROG_NAME_LENGTH != 128) ?
			ft_printf(MAG"Warning:"RESET " PROG_NAME_LENGTH != 128\n") : 0;
		(COMMENT_LENGTH != 2048) ?
			ft_printf(MAG"Warning:"RESET " COMMENT_LENGTH != 2048\n") : 0;
		exit(4);
	}
	else if ((MAX_PLAYERS != 4) || (MAX_ARGS_NUMBER != 4))
	{
		(MAX_PLAYERS != 4) ?
			ft_printf(MAG"Warning:"RESET " MAX_PLAYERS != 4\n") : 0;
		(MAX_ARGS_NUMBER != 4) ?
			ft_printf(MAG"Warning:"RESET " MAX_ARGS_NUMBER != 4\n") : 0;
		exit(5);
	}
	else if ((REG_NUMBER < 0) || (CYCLE_TO_DIE < 0) || (NBR_LIVE < 0) ||
			(MAX_CHECKS) < 0 || (CYCLE_DELTA < 0))
	{
		ft_printf(MAG"Warning:"RESET " No negative instructions please.\n");
		exit(6);
	}
}

void	usage_e(void)
{
	ft_printf(YEL"Usage: ./corewar     [-dump nbr_cycles] [-n number] [-v] "
			"[-a] <champion1.cor> <...>\n"RESET
			"    -a               : Prints output from \"aff\" "
			"(Default is to hide it)\n"
			"    -n number        : Sets the number of the next player\n"
			"###################### MAP OUTPUT MODE #########################\n"
			"    -dump nbr_cycles : Dumps memory after nbr_cycles then exits\n"
			"#################### NCURSES OUTPUT MODE #######################\n"
			"    -v               : Ncurses output mode\n");
	exit(1);
}
