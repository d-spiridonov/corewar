/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 13:14:08 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 20:31:43 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../corewar.h"

typedef struct s_file	t_file;
typedef struct s_labels	t_labels;

struct				s_labels
{
	char			*str;
	t_labels		*next;
};

struct				s_file
{
	char			*file_name;
	char			*name;
	char			*comm;
	t_labels		*labels;
	t_file			*next;
};

typedef struct		s_asm
{
	int				a;
	int				p;
	int				ll;
	int				li;
	int				lc;
	int				c;
	int				fd;
	int				f_name;
	int				f_comment;
	int				line;
	int				l;
	int				q;
	int				last;
	int				count;
	int				last_line;
	unsigned int	prog_size;
	int				t;
	int				d;
	int				s;
	int				w;
	int				last_mas;
	int				last_det;
	int				last_stn;
	int				label;
	int				label1;
	t_header		header;
}					t_asm;

extern t_asm		g_asm;
extern t_file		*g_file;

int					print_usage(int i, char *s);
int					print_usage_1(int i, char *s, int param, char *p);
int					print_usage_0(int i, char *s);
void				lets_get_null(void);
void				lets_get_null_for_file(void);
int					g_validation(char *str, char *line);
t_file				*record_file(char *str, int y);
int					record_labels(char *line);
void				add_file(t_file *file, char *str);
void				add_label(char *line, t_labels *labels);
int					looking_for_errors(t_file *t, int n);
int					checkout_name_comm(t_labels *tmp, int a);
int					check_comment(t_labels *tmp, int i, int a);
int					check_no_repit(t_labels *tmp);
t_labels			*skip_blank_lines(t_labels *tmp, int f);
int					finaly_check_name_comm(t_labels *tmp, int i, int n, int a);
int					checkout_body(t_labels *tmp, int a, int i);
int					check_param(t_labels *tmp, int i);
int					find_n(t_labels *tmp, int i, int l);
int					find_char(char c, int i);
int					instruction_with_one_param(t_labels *tmp, int i);
int					check_direct(t_labels *t, int i, int q, int last);
int					check_separator(t_labels *tmp, int q, int i);
int					find_label(t_labels *q, t_file *t, int i, size_t c);
int					check_all_labels(int p);
t_labels			*leaf_list(t_file *t);
int					check_registry(t_labels *tmp, int i, int q, int last);
int					check_indirect(t_labels *tmp, int i, int q, int last);
int					instruction_with_three_param1_1_1(t_labels *tmp, int i);
int					instruction_with_three_param3_3_1(t_labels *tmp, int i);
int					instruction_with_two_param2_1(t_labels *tmp, int i, int n);
int					instruction_with_three_param3_2_1(t_labels *tmp, int i);
int					instruction_with_three_param1_3_2(t_labels *tmp, int i);
void				skip_separator_between_param(t_labels *tmp);
int					check_three(t_labels *tmp, int i, int number);
int					check_two(t_labels *tmp, int i, int hm, int number);
int					check_two_1(t_labels *tmp, int i, int hm, int number);
int					is_it_label(t_labels *tmp, int i);
char				*usage(void);
int					no_emty(t_file *t, int i, t_labels *tmp);
int					name_s(char *str, char *argv);
char				*change_file_name(t_file *t);
void				create_file(t_file *t);
void				print_with_a(t_file *t);
void				prog_size_magic_n_c(t_file *t, t_labels *tm, int i, int q);
void				count_par_b(short numder_arg, t_labels *tmp, int i, int p);
unsigned int		convert(unsigned int s);
void				write_body(t_labels *tmp, int i);
int					write_codage(t_labels *t, int i, int p, int codage);
int					first_second_arg_codage(t_labels *t, int p, int number);
int					leaf_p(t_labels *tmp, int p);
int					third_arg_codage(t_labels *t, int p);
void				write_param(t_labels *t, int i);
unsigned int		swap(unsigned int s, int dir_size);
char				*write_direct(char *s, t_labels *t, unsigned int q, int i);
char				*write_register(char *str, int count, unsigned int q);
char				*write_indirect(char *s, t_labels *t, unsigned int q);
int					find_label_to_writ(char *str, t_labels *tmp, int c,
										size_t i);
int					find_line_for_instruction(t_labels *tmp, t_file *t);
int					count_par_fn(short numder_arg, t_labels *tmp, int i, int p);
int					find_size_of_prog_here(int line, t_file *t);
char				*print_label(char *s, unsigned int q, t_labels *t, int dir);
int					find_quote(t_labels *tmp, int i, int n, int t);
int					finaly_check_n_n(t_file *tmp, int i, int a, t_labels *t);
void				write_fu_name_comm(t_file *tmp, t_labels *t, int a, int i);
int					prog_size(t_labels *tmp, int i);
void				print_body(t_labels *tmp, int i, int before, int after);
void				print_label_output(int before, t_labels *tmp);
void				print_instruction(t_labels *tmp, int i, int count);
void				print_details(t_labels *tmp, int i, int	p, int c);
char				*write_dir_out(char *s, t_labels *t, unsigned int q, int i);
unsigned char		magic(int shift, unsigned int m);
char				*wrt_indir_out(char *s, t_labels *t, unsigned int q);
void				count_write_codage_opcode_a(t_labels *tmp, int i);
void				print_standart_info(t_labels *tmp, int i, int c, int p);
char				*w_dir_out_stn(char *s, t_labels *t, unsigned int q);
char				*w_indir_out_stn(char *s, t_labels *t, unsigned int q);
int					fnd_l_for_ins_a(t_labels *tmp, t_file *t, int lst_l, int n);
t_labels			*name_comm(t_labels *tmp, int n, int a);
int					name_length(t_file *t);
t_labels			*check_n_n(t_file *tmp, int i, int a, t_labels *t);
t_labels			*leaf(t_file *t, t_labels *tmp);
char				*leaf_str(char *str);
int					count_n(t_labels *tmp, int n, int i);
void				name_co(t_file *tmp, t_labels *t, int a);
int					for_check_registry(t_labels *tmp, char *str);
int					find_n_for_size(t_labels *tmp, int i, int l);
int					find_after_l(t_labels *tmp, int d, int i, char *t);

#endif
