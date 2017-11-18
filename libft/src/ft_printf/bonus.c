/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 19:39:31 by kzakharc          #+#    #+#             */
/*   Updated: 2017/06/14 19:13:16 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	record_n(va_list ap, t_uck *s)
{
	int	*i;

	i = va_arg(ap, void *);
	*i = s->count;
}

void	print_b(va_list ap, t_uck *s, const char **r_f)
{
	get_null(s);
	s->str = i(va_arg(ap, int), 2, 0);
	if (ft_strlen(s->str) < 8)
	{
		s->ze = 1;
		s->width = 1;
		s->i_w = 8;
	}
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
	s->str_clear == 1 ? 0 : free(s->str);
}

void	check_flags_(const char **r_form, t_uck *s)
{
	(**r_form == '-') ? (s->hyphen = 1) : 0;
	(**r_form == '+') ? (s->plus = 1) : 0;
	(**r_form == ' ') ? (s->space = 1) : 0;
	(**r_form == '#') ? (s->has = 1) : 0;
	(**r_form == '0') ? (s->ze = 1) : 0;
	(**r_form == 'j') ? (s->j = 1) : 0;
	(**r_form == 'z') ? (s->z = 1) : 0;
}

void	get_big_s_(int *q, t_uck *s)
{
	if_one(s, q);
	s->i_p--;
	(s->width == 1) ? (s->i_w--) : 0;
	(s->width == 1) ? (s->count_1--) : 0;
}

void	so_much(t_uck *s)
{
	if ((s->i_p <= (int)(ft_strlen(s->str) + 1)) && (s->has == 1))
		s->prec = 0;
	else
		s->has = 0;
}
