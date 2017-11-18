/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtualm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:15:29 by vpoltave          #+#    #+#             */
/*   Updated: 2017/10/24 21:29:42 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUALM_H
# define VIRTUALM_H

/*
**	defines for lseeks, go -> [vp_basic.c]
*/

# define COMMENT_POS	(PROG_NAME_LENGTH + 13 - ((PROG_NAME_LENGTH + 1) % 4))
# define SIZE_POS		(PROG_NAME_LENGTH + 9 - ((PROG_NAME_LENGTH + 1) % 4))
# define COMMANDS_POS	(COMMENT_POS + COMMENT_LENGTH + 4)

# include "../../corewar.h"

/*
**	struct for op_tab, which have inside all information about instructions.
*/

typedef struct			s_op
{
	char				*name;
	short				numb_of_arg;
	t_arg_type			arg[3];
	short				opcode;
	short				cycles;
	short				codage;
	short				dir_size;
}						t_op;

/*
**	linked lists for process.
*/

typedef struct			s_proc
{
	int					id;
	int					pc;
	int					tmp_pc;
	unsigned int		registry[REG_NUMBER];
	int					carry;
	int					live_proc;
	int					live_color;
	int					live_pc;
	int					waiting_cycles;
	int					sop;
	struct s_proc		*next;
}						t_proc;

/*
**	linked lists for champs.
*/

typedef struct			s_chmp
{
	int					id;
	int					fd;
	int					ac;
	unsigned int		reg_value;
	int					offset;
	unsigned int		player_pos;
	int					live_count;
	long				last_live;
	t_header			header;
	struct s_chmp		*next;
}						t_chmp;

/*
**	basic struct for additional info.
** 	n -> iterator for players,
**	init_id -> for init id in chmps and processes
**	shift -> for shifts bits in some functions,
** 	process_count -> for count all processes
*/

typedef struct s_vis	t_vis;

typedef struct			s_skrr
{
	int					fd;
	unsigned int		i;
	int					j;
	int					n;
	int					op;
	int					init_id;
	int					shift;
	int					max_checks;
	int					nbr_live;
	int					cycle_to_die;
	int					process_count;
	int					*flag_n;
	int					cnt_n;
	int					flag_v;
	int					flag_dump;
	int					flag_a;
	int					max_player;
	unsigned char		map[MEM_SIZE];
	unsigned char		mapid[MEM_SIZE];
	t_chmp				*chmp;
	t_proc				*process;
	t_vis				*vis;
}						t_skrr;

/*
**	global variables, g_inter - global itearator,
**  op_tab array with info about instructions.
*/

extern t_op				g_tab[17];
extern unsigned long	g_cycles;
extern int				g_ctd;
extern int				g_err;

/*
**	usage and open checks functions.  go -> [ft_error_output.c]
*/

void					usage_e(void);
void					chk_open(t_skrr *skrr, char **argv, int argc, int flag);
void					header_errors(void);
void					header_errors_2(void);
void					argv_error(t_skrr *skrr, char **argv, int flag);

/*
** init function. go -> [init_skrr_&_global.c] for init all structure variables.
*/

void					init(t_skrr *skrr);
void					init_flag(t_skrr *skrr);
int						fuck_norm(t_skrr *skrr, t_proc *process, int sop);
void					fuck_norm_2(t_skrr *skrr, t_proc *process, int reg,
								int address);

/*
**	main functions, for get info about "name", "weighing",
**  "comments" .. go -> [vp_basic.c].
*/

void					just_read(t_skrr *skrr, char *argv, t_chmp *chmp);
unsigned int			get_magic_size(unsigned int m, int shift);
void					get_name_comm(t_skrr *skrr, char *argv, t_chmp *chmp);
void					vm_prog_size(t_skrr *skrr, char *argv, t_chmp *chmp);
void					chk_size(t_skrr *skrr, char *argv, unsigned char *line,
								t_chmp *chmp);

/*
**	commands functions. Func for global while and stuff.
*/

void					prog_commands(t_skrr *skrr, char **av, t_chmp *chmp);
unsigned int			player_position(int nbr, t_skrr *skrr, t_chmp *chmp);
void					unsafe_copy(t_skrr *skrr, unsigned char *src,
								t_chmp *chmp);
int						entry_point(t_skrr *skrr, t_chmp *chmp);
void					which_instr(t_skrr *skrr, t_proc **pr);
int						change_process(t_skrr *skrr, t_chmp *chmp,
								t_proc **process);
int						process_first_pos(t_chmp *chmp, t_proc *process);
void					kill_processes(t_proc **process, t_skrr *skrr);
void					winner(t_chmp *chmp, t_skrr *skrr, long best_cycle,
								int best_player);
int						init_lives(t_skrr *skrr);

/*
**	Adding new champ and init his data. go -> [new_chmp.c].
*/

int						push_chmp(t_chmp **head, t_skrr *skrr);
void					init_data(t_chmp *champ, t_skrr *skrr);
int						push_process(t_proc **process, t_skrr *skrr, int id);

/*
**	Instructions. live, st ..
**  etc go -> [./instructions/[name of instructions].c] etc ..
*/

int						live_instr(t_skrr *skrr, t_proc *process);
int						ld_instr(t_skrr *skrr, t_proc *process);
int						st_instr(t_skrr *skrr, t_proc *process);
int						add_instr(t_skrr *skrr, t_proc *process);
int						sub_instr(t_skrr *skrr, t_proc *process);
int						and_instr(t_skrr *skrr, t_proc *process);
int						or_instr(t_skrr *skrr, t_proc *process);
int						xor_instr(t_skrr *skrr, t_proc *process);
int						zjmp_instr(t_skrr *skrr, t_proc *process);
int						ldi_instr(t_skrr *skrr, t_proc *process);
int						sti_instr(t_skrr *skrr, t_proc *process);
int						fork_instr(t_skrr *skrr, t_proc **process);
int						lld_instr(t_skrr *skrr, t_proc *process);
int						lldi_instr(t_skrr *skrr, t_proc *process);
int						lfork_instr(t_skrr *skrr, t_proc **process);
int						aff_instr(t_skrr *skrr, t_proc *process);

/*
**	additional func for instr.
*/

unsigned char			hex_to_bin(unsigned char c, int i);
unsigned int			two_four_bytes(unsigned char *map, int dir_size);
int						from_reg(unsigned char *q, t_proc *process,
								t_skrr *skrr, short i);
unsigned char			arg_types(t_skrr *skrr, t_chmp *chmp, int ctk);
int						get_address(unsigned char *q, t_skrr *skrr,
								t_proc *process, short i);
int						simple_address(unsigned char *q, t_skrr *skrr,
								t_proc *process, short i);
int						load_into(int address, t_proc *process, t_skrr *skrr,
								int flag);
int						same_start(unsigned char *q, t_skrr *skrr,
								t_proc *process, int num_arg);
int						det_of_action(unsigned char *q, t_skrr *skrr, int key,
								t_proc *process);
int						inheritance_proc(t_proc **process, int pc,
								t_skrr *skrr);
int						check_my_q(unsigned char *q, int num_arg, t_skrr *skrr);

int						reg_param(t_skrr *skrr,
								t_proc *process, int flag);
int						dir_param(t_skrr *skrr, t_proc *process,
								short dir_size);
int						ind_param(t_skrr *skrr, t_proc *process, int bytes);

/*
**	init map and print map
*/

void					init_map(t_skrr *skrr);
void					print_map(t_skrr *skrr);
/*
**	printing all players and their info.
*/

void					print_info(t_chmp *chmp);
void					dump_print(t_skrr *skrr);

/*
** function for flags
*/

int						ft_intc(const int *mass, int c, int length);
int						*ft_intmalloc(size_t size);
int						len_value(int value);
void					parsing_arg(t_skrr *skrr, char **av, int ac);
void					flag_n(t_skrr *skrr);
void					n(char **av, int *i, t_skrr *skrr, int ac);
void					dump(char **av, int *i, t_skrr *skrr);
void					a(char **av, int *i, t_skrr *skrr);
unsigned int			zero_reg(t_skrr *skrr);

#endif
