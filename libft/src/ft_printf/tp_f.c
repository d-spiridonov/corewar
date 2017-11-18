/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 20:22:24 by kzakharc          #+#    #+#             */
/*   Updated: 2017/06/14 19:15:29 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	print_d_i(va_list ap, t_uck *s, const char **r_f)
{
	s->has = 0;
	if ((s->hh == 1) || (s->h == 1) || (s->l == 1) || (s->ll == 1) ||
			(s->j == 1) || (s->z == 1))
	{
		(s->hh == 1) ? (s->str = ft_b((signed char)va_arg(ap, int), 10)) : 0;
		(s->h == 1) ? (s->str = ft_b((short)va_arg(ap, int), 10)) : 0;
		(s->l == 1) ? (s->str = ft_b(va_arg(ap, long), 10)) : 0;
		(s->ll == 1) ? (s->str = ft_b(va_arg(ap, long long), 10)) : 0;
		(s->j == 1) ? (s->str = ft_b(va_arg(ap, intmax_t), 10)) : 0;
		(s->z == 1) ? (s->str = ft_b(va_arg(ap, size_t), 10)) : 0;
	}
	else
		s->str = ft_b(va_arg(ap, int), 10);
	((s->prec == 1) && (s->i_p >= 0)) ? (s->ze = 0) : 0;
	if ((s->str[0] == '-') && (s->prec == 1))
	{
		(s->str = change_for_prec(s, 1));
		s->prec = 0;
		(s->i >= 1) ? (s->str = ft_strjoin("-", s->str)) : 0;
	}
	for_d(s, &(*r_f));
}

void	print_bd(va_list ap, t_uck *s, const char **r_f)
{
	s->has = 0;
	if ((s->hh == 1) || (s->h == 1) || (s->l == 1) || (s->ll == 1) ||
			(s->j == 1) || (s->z == 1))
	{
		(s->hh == 1) ? (s->l = 1) : 0;
		(s->h == 1) ? (s->l = 1) : 0;
		(s->l == 1) ? (s->str = ft_b(va_arg(ap, long), 10)) : 0;
		(s->ll == 1) ? (s->str = ft_b(va_arg(ap, long long), 10)) : 0;
		(s->j == 1) ? (s->str = ft_b(va_arg(ap, intmax_t), 10)) : 0;
		(s->z == 1) ? (s->str = ft_b(va_arg(ap, size_t), 10)) : 0;
	}
	else
		s->str = ft_b(va_arg(ap, long), 10);
	if ((s->str[0] == '0') && (!(s->i_p) && s->prec == 1))
		ft_strclr(s->str);
	(s->prec == 1) ? (s->str = change_for_prec(s, 0)) : 0;
	((s->prec == 1) && (s->i_p > 0)) ? (s->ze = 0) : 0;
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
}

void	print_o(va_list ap, t_uck *s, const char **r_f)
{
	s->plus = 0;
	s->space = 0;
	if ((s->hh) || (s->h) || (s->l) || (s->ll) || (s->j) || (s->z))
	{
		(s->hh == 1) ? (s->str = i((unsigned char)va_arg(ap, int), 8, 0)) : 0;
		(s->h == 1) ? (s->str = i((unsigned short)va_arg(ap, int), 8, 0)) : 0;
		(s->l == 1) ? (s->str = i(va_arg(ap, unsigned long), 8, 0)) : 0;
		(s->ll == 1) ? (s->str = i(va_arg(ap, unsigned long long), 8, 0)) : 0;
		(s->j == 1) ? (s->str = i(va_arg(ap, intmax_t), 8, 0)) : 0;
		(s->z == 1) ? (s->str = i(va_arg(ap, size_t), 8, 0)) : 0;
	}
	else
		s->str = i((unsigned int)va_arg(ap, int), 8, 0);
	((s->str[0] == '0') && (!(s->i_p) && s->prec == 1)) ? ft_strclr(s->str) : 0;
	if ((s->str[0] == '0') && !(s->has = 0))
	{
		s->str = ft_strnew(1);
		s->str[0] = '0';
	}
	((s->prec == 1) && (s->i_p > 0)) ? (s->ze = 0) : 0;
	so_much(s);
	(s->prec == 1) ? (s->str = change_for_prec(s, 0)) : 0;
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
	s->str_clear == 1 ? 0 : free(s->str);
}

void	print_bo(va_list ap, t_uck *s, const char **r_f)
{
	s->plus = 0;
	s->space = 0;
	if ((s->hh) || (s->h) || (s->l) || (s->ll) || (s->j) || (s->z))
	{
		(s->hh == 1) ? (s->l = 1) : 0;
		(s->h == 1) ? (s->l = 1) : 0;
		(s->l == 1) ? (s->str = i(va_arg(ap, unsigned long), 8, 0)) : 0;
		(s->ll == 1) ? (s->str = i(va_arg(ap, unsigned long long), 8, 0)) : 0;
		(s->j == 1) ? (s->str = i(va_arg(ap, intmax_t), 8, 0)) : 0;
		(s->z == 1) ? (s->str = i(va_arg(ap, size_t), 8, 0)) : 0;
	}
	else
		s->str = i(va_arg(ap, unsigned long), 8, 0);
	((s->str[0] == '0') && (!(s->i_p) && s->prec == 1)) ? ft_strclr(s->str) : 0;
	if ((s->str[0] == '0') && !(s->has = 0))
	{
		s->str = ft_strnew(1);
		s->str[0] = '0';
	}
	((s->prec == 1) && (s->i_p > 0)) ? (s->ze = 0) : 0;
	so_much(s);
	(s->prec == 1) ? (s->str = change_for_prec(s, 0)) : 0;
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
}

void	print_s(va_list ap, t_uck *s, const char **r_f)
{
	s->plus = 0;
	s->space = 0;
	s->has = 0;
	s->str = (va_arg(ap, char *));
	(s->str == NULL) ? (s->str = "(null)") : 0;
	((s->prec == 1) && (s->i_p >= 0)) ? (s->str = change_for_prec_s(s)) : 0;
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
}
