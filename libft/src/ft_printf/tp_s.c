/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 20:27:06 by kzakharc          #+#    #+#             */
/*   Updated: 2017/06/13 21:39:37 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	print_x(va_list ap, t_uck *s, const char **r_f)
{
	s->plus = 0;
	s->space = 0;
	if ((s->hh) || (s->h) || (s->l) || (s->ll) || (s->j) || (s->z))
	{
		(s->hh == 1) ? (s->str = i((unsigned char)va_arg(ap, int), 16, 1)) : 0;
		(s->h == 1) ? (s->str = i((unsigned short)va_arg(ap, int), 16, 1)) : 0;
		(s->l == 1) ? (s->str = i(va_arg(ap, unsigned long), 16, 1)) : 0;
		(s->ll == 1) ? (s->str = i(va_arg(ap, unsigned long long), 16, 1)) : 0;
		(s->j == 1) ? (s->str = i(va_arg(ap, intmax_t), 16, 1)) : 0;
		(s->z == 1) ? (s->str = i(va_arg(ap, size_t), 16, 1)) : 0;
	}
	else
		s->str = i((unsigned int)va_arg(ap, int), 16, 1);
	if (s->str[0] == '0')
	{
		(**r_f != 'p') ? (s->has = 0) : 0;
		s->str = (char *)malloc(sizeof(char) * 2);
		s->str[0] = '0';
		s->str[1] = '\0';
	}
	((s->str[0] == '0') && (!(s->i_p) && s->prec == 1)) ? ft_strclr(s->str) : 0;
	(s->prec == 1) ? (s->str = change_for_prec(s, 0)) : 0;
	((s->prec == 1) && (s->i_p > 0)) ? (s->ze = 0) : 0;
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
	s->str_clear == 1 ? 0 : free(s->str);
}

void	print_bx(va_list ap, t_uck *s, const char **r_f)
{
	s->plus = 0;
	s->space = 0;
	if ((s->hh) || (s->h) || (s->l) || (s->ll) || (s->j) || (s->z))
	{
		(s->hh == 1) ? (s->str = i((unsigned char)va_arg(ap, int), 16, 2)) : 0;
		(s->h == 1) ? (s->str = i((unsigned short)va_arg(ap, int), 16, 2)) : 0;
		(s->l == 1) ? (s->str = i(va_arg(ap, unsigned long), 16, 2)) : 0;
		(s->ll == 1) ? (s->str = i(va_arg(ap, unsigned long long), 16, 2)) : 0;
		(s->j == 1) ? (s->str = i(va_arg(ap, intmax_t), 16, 2)) : 0;
		(s->z == 1) ? (s->str = i(va_arg(ap, size_t), 16, 2)) : 0;
	}
	else
		s->str = i((unsigned int)va_arg(ap, int), 16, 2);
	if ((s->str[0] == '0') && !(s->has = 0))
	{
		s->str = (char *)malloc(sizeof(char) * 2);
		s->str[0] = '0';
		s->str[1] = '\0';
	}
	if ((s->str[0] == '0') && (!(s->i_p) && s->prec == 1))
		ft_strclr(s->str);
	(s->prec == 1) ? (s->str = change_for_prec(s, 0)) : 0;
	((s->prec == 1) && (s->i_p > 0)) ? (s->ze = 0) : 0;
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
	s->str_clear == 1 ? 0 : free(s->str);
}

void	print_c(va_list ap, t_uck *s, const char **r_f)
{
	s->prec = 0;
	s->plus = 0;
	s->has = 0;
	s->space = 0;
	s->c = va_arg(ap, int);
	s->str = (char *)malloc(sizeof(char) * 2);
	s->str[0] = s->c;
	s->str[1] = '\0';
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
}

void	print_u(va_list ap, t_uck *s, const char **r_f)
{
	s->plus = 0;
	s->space = 0;
	s->has = 0;
	if ((s->hh) || (s->h) || (s->l) || (s->ll) || (s->j) || (s->z))
	{
		(s->hh == 1) ? (s->str = i((unsigned char)va_arg(ap, int), 10, 0)) : 0;
		(s->h == 1) ? (s->str = i((unsigned short)va_arg(ap, int), 10, 0)) : 0;
		(s->l == 1) ? (s->str = i(va_arg(ap, unsigned long), 10, 0)) : 0;
		(s->ll == 1) ? (s->str = i(va_arg(ap, unsigned long long), 10, 0)) : 0;
		(s->j == 1) ? (s->str = i(va_arg(ap, intmax_t), 10, 0)) : 0;
		(s->z == 1) ? (s->str = i(va_arg(ap, size_t), 10, 0)) : 0;
	}
	else
		s->str = i((unsigned int)va_arg(ap, int), 10, 0);
	((s->str[0] == '0') && (!(s->i_p) && s->prec == 1)) ? ft_strclr(s->str) : 0;
	if (s->str[0] == '0')
	{
		s->str = (char *)malloc(sizeof(char) * 2);
		s->str[0] = '0';
		s->str[1] = '\0';
	}
	(s->prec == 1) ? (s->str = change_for_prec(s, 0)) : 0;
	((s->prec == 1) && (s->i_p > 0)) ? (s->ze = 0) : 0;
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
	s->str_clear == 1 ? 0 : free(s->str);
}

void	print_bu(va_list ap, t_uck *s, const char **r_f)
{
	s->plus = 0;
	s->space = 0;
	s->has = 0;
	if ((s->hh) || (s->h) || (s->l) || (s->ll) || (s->j) || (s->z))
	{
		(s->hh == 1) ? (s->l = 1) : 0;
		(s->h == 1) ? (s->l = 1) : 0;
		(s->l == 1) ? (s->str = i(va_arg(ap, unsigned long), 10, 0)) : 0;
		(s->ll == 1) ? (s->str = i(va_arg(ap, unsigned long long), 10, 0)) : 0;
		(s->j == 1) ? (s->str = i(va_arg(ap, intmax_t), 10, 0)) : 0;
		(s->z == 1) ? (s->str = i(va_arg(ap, size_t), 10, 0)) : 0;
	}
	else
		s->str = i(va_arg(ap, unsigned long), 10, 0);
	((s->str[0] == '0') && (!(s->i_p) && s->prec == 1)) ? ft_strclr(s->str) : 0;
	if (s->str[0] == '0')
	{
		s->str = (char *)malloc(sizeof(char) * 2);
		s->str[0] = '0';
		s->str[1] = '\0';
	}
	(s->prec == 1) ? (s->str = change_for_prec(s, 0)) : 0;
	((s->prec == 1) && (s->i_p > 0)) ? (s->ze = 0) : 0;
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
	s->str_clear == 1 ? 0 : free(s->str);
}
