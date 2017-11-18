/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_bc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:31:32 by kzakharc          #+#    #+#             */
/*   Updated: 2017/06/14 19:16:32 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	pr_bc(va_list ap, t_uck *s, const char **r_f)
{
	int		dummy;
	int		q;
	char	*d;

	s->w = 0;
	dummy = 0;
	s->prec = 0;
	s->plus = 0;
	s->has = 0;
	s->space = 0;
	d = ft_strnew(0);
	s->str = d;
	free(d);
	q = (va_arg(ap, int));
	get_big_c(&q, s, dummy);
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
}

void	get_big_c(int *q, t_uck *s, int dummy)
{
	if ((*q >= 0) && (*q < 128))
		if_one(s, q);
	else if ((*q >= 256) && (*q < 2048))
		if_two(s, q, dummy);
	else if ((*q >= 2048) && (*q < 65536))
		if_three(s, q, dummy);
}
