/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:22:44 by kzakharc          #+#    #+#             */
/*   Updated: 2017/06/14 20:22:31 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

# define BLA	"\x1B[30m"
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define BRED	"\x1B[41m"
# define BGRN	"\x1B[42m"
# define BYEL	"\x1B[43m"
# define BBLU	"\x1B[44m"
# define BMAG	"\x1B[45m"
# define BCYN	"\x1B[46m"
# define BWHT	"\x1B[47m"
# define UNDER	"\e[4m"
# define BLINK	"\e[5m"
# define REVER	"\e[7m"
# define CONC	"\e[8m"
# define BOLD	"\e[1m"
# define DIM	"\e[2m"
# define NORM	"\e[24m"
# define RESET	"\x1B[0m"

typedef struct		s_uck
{
	char			*f;
	char			*tp;
	int				count;
	int				count_1;
	int				i_w;
	int				i_p;
	int				hyphen;
	int				plus;
	int				space;
	int				has;
	int				ze;
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				j;
	int				z;
	char			*str;
	char			*str_p;
	unsigned char	c;
	int				width;
	int				prec;
	int				k;
	int				i;
	int				str_clear;
	int				w;
	char			*d;
	int				how;
	int				low;
}					t_uck;

int					ft_printf(const char *r_form, ...);
char				*ft_b(intmax_t value, int base);
char				*i(uintmax_t value, int base, int flag);
void				print_d_i(va_list ap, t_uck *s, const char **r_f);
void				print_bd(va_list ap, t_uck *s, const char **r_f);
void				print_o(va_list ap, t_uck *s, const char **r_f);
void				print_bo(va_list ap, t_uck *s, const char **r_f);
void				print_s(va_list ap, t_uck *s, const char **r_f);
void				print_b(va_list ap, t_uck *s, const char **r_f);
void				record_n(va_list ap, t_uck *s);
void				pr_bs(va_list ap, t_uck *s, const char **r_f);
void				print_x(va_list ap, t_uck *s, const char **r_f);
void				print_bx(va_list ap, t_uck *s, const char **r_f);
void				print_c(va_list ap, t_uck *s, const char **r_f);
void				print_u(va_list ap, t_uck *s, const char **r_f);
void				print_bu(va_list ap, t_uck *s, const char **r_f);
void				ch_w(const char **r_form, va_list ap, t_uck *s);
void				ch_p(const char **r_form, va_list ap, t_uck *s);
char				*change_for_prec(t_uck *s, int f);
char				*change_for_prec_s(t_uck *s);
void				print_w(t_uck *s, const char **r_f);
void				print(t_uck *s, const char **r_f);
void				if_hash(t_uck *s, const char **r_f, int i);
void				if_plus(t_uck *s, const char **r_f, int i);
void				if_space(t_uck *s, const char **r_f, int i);
void				hyp_print(t_uck *s, const char **r);
void				without_hyp_print(t_uck *s, const char **r);
void				get_null(t_uck *s);
void				p_t(t_uck *s, const char **r_f);
void				find_dominant(t_uck *s);
void				find_little_dominant(t_uck *s);
void				for_d(t_uck *s, const char **r_f);
char				*get_memory(int size, t_uck *s, int i);
void				if_one(t_uck *s, int *q);
void				if_two(t_uck *s, int *q, int dummy);
void				if_three(t_uck *s, int *q, int dummy);
void				get_big_s(int *q, t_uck *s, int dummy);
void				get_big_s_no_prec(int *q, t_uck *s, int dummy);
void				pr_bc(va_list ap, t_uck *s, const char **r_f);
void				get_big_c(int *q, t_uck *s, int dummy);
void				check_flags_(const char **r_form, t_uck *s);
void				get_big_s_(int *q, t_uck *s);
void				so_much(t_uck *s);

#endif
