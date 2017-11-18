/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:44:53 by kzakharc          #+#    #+#             */
/*   Updated: 2017/06/14 19:07:45 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	hyp_print(t_uck *s, const char **r)
{
	(s->has == 1) ? if_hash(s, &(*r), 0) : 0;
	(s->plus == 1) ? if_plus(s, &(*r), 0) : 0;
	((s->space == 1) && (s->plus != 1)) ? if_space(s, &(*r), 0) : 0;
	((**r == 'c') || (**r == 'C')) ? (ft_putchar(s->c)) : ft_putstr(s->str);
	s->count_1 += ((s->str[0] != '\0') || (**r == 's')) ? ft_strlen(s->str) : 1;
	s->count += ((s->str[0] != '\0') || (**r == 's')) ? ft_strlen(s->str) : 1;
	s->i_w -= s->count_1;
	if (s->ze == 1)
	{
		while (s->i_w)
		{
			ft_putchar('0');
			s->i_w -= 1;
			s->count += 1;
		}
	}
	else
	{
		while (s->i_w)
		{
			ft_putchar(' ');
			s->i_w -= 1;
			s->count += 1;
		}
	}
}

void	without_hyp_print(t_uck *s, const char **r)
{
	s->count += ft_strlen(s->str);
	s->count_1 += ft_strlen(s->str);
	((s->str[0] == '\0') && (**r == 'c')) ? (s->count_1 += 1) : 0;
	s->i_w -= s->count_1;
	if (((((s->prec) && (s->i_p > s->count_1)) || (s->ze)) && (s->width) &&
			**r != 'p') || (**r == 'p' && !(s->prec) && s->width && s->hyphen))
		(s->has == 1) ? if_hash(s, &(*r), 0) : 0;
	((s->plus == 1) && (s->ze == 1)) ? if_plus(s, &(*r), 0) : 0;
	((s->space == 1) && (s->plus != 1)) ? if_space(s, &(*r), 0) : 0;
	while (s->i_w)
	{
		(s->ze == 1) ? (ft_putchar('0')) : (ft_putchar(' '));
		s->i_w -= 1;
		s->count += 1;
	}
	((s->plus == 1) && (s->ze == 0)) ? if_plus(s, &(*r), 0) : 0;
	if ((((s->prec == 0) || s->i_p <= s->count_1) || (**r == 'p')) && (s->has))
		if_hash(s, &(*r), 0);
	if ((s->str[0] == '\0') && (**r == 'c'))
	{
		s->count += 1;
		ft_putchar('\0');
	}
	else
		ft_putstr(s->str);
}

void	print(t_uck *s, const char **r_f)
{
	(s->hyphen == 1) ? (s->ze = 0) : 0;
	(s->has == 1) ? if_hash(s, &(*r_f), 1) : 0;
	(s->plus == 1) ? if_plus(s, &(*r_f), 1) : 0;
	((s->space == 1) && (s->plus != 1)) ? if_space(s, &(*r_f), 1) : 0;
	s->count += ft_strlen(s->str);
	(s->has == 1) ? if_hash(s, &(*r_f), 0) : 0;
	(s->plus == 1) ? if_plus(s, &(*r_f), 0) : 0;
	((s->space == 1) && (s->plus != 1)) ? if_space(s, &(*r_f), 0) : 0;
	if ((s->str[0] == '\0') && ((**r_f == 'c') || (**r_f == 'C')))
	{
		s->count += 1;
		ft_putchar('\0');
	}
	else
		ft_putstr(s->str);
	if ((**r_f == 'c') && (s->l == 0))
		free(s->str);
	if ((**r_f != 's') && (**r_f != 'S') && (**r_f != 'C') &&
			(**r_f != 'c'))
		free(s->str);
	s->str_clear = 1;
}

void	p_t(t_uck *s, const char **r_f)
{
	s->space = 0;
	s->str = (char *)malloc(sizeof(char) * 2);
	s->str[0] = **r_f;
	s->str[1] = '\0';
	if (s->str[0] == '0')
		ft_strclr(s->str);
	(s->width == 1) ? (print_w(s, &(*r_f))) : (print(s, &(*r_f)));
	s->str_clear == 1 ? 0 : free(s->str);
	(*r_f)++;
}
