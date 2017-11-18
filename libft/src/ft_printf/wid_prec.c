/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wid_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:02:05 by kzakharc          #+#    #+#             */
/*   Updated: 2017/06/14 19:13:48 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*change_for_prec(t_uck *s, int f)
{
	s->k = (int)ft_strlen(s->str);
	s->str_p = (char *)malloc(sizeof(char) * (s->i_p + 1));
	if (f == 1)
		s->k--;
	if (s->i_p <= s->k)
		return (s->str);
	else if (s->i_p > s->k)
	{
		while (s->i_p != s->k)
		{
			s->str_p[s->i] = '0';
			s->i_p--;
			s->i++;
		}
		s->str_p[s->i] = '\0';
		s->d = s->str_p;
		if (f == 0)
			s->str_p = ft_strjoin(s->str_p, s->str);
		else if (f == 1)
			s->str_p = ft_strjoin(s->str_p, (s->str + 1));
		free(s->d);
		free(s->str);
		return (s->str_p);
	}
	return (s->str);
}

char	*change_for_prec_s(t_uck *s)
{
	int c;

	c = 0;
	s->str_p = (char *)malloc(sizeof(char) * (s->i_p + 1));
	if (s->i_p < (int)ft_strlen(s->str))
	{
		while (c < s->i_p)
		{
			s->str_p[c] = s->str[c];
			c++;
		}
		s->str_p[c] = '\0';
		return (s->str_p);
	}
	else
		return (s->str);
}

void	print_w(t_uck *s, const char **r_f)
{
	(s->has == 1) ? if_hash(s, &(*r_f), 1) : 0;
	(s->plus == 1) ? if_plus(s, &(*r_f), 1) : 0;
	(s->hyphen == 1) ? (s->ze = 0) : 0;
	((s->space == 1) && (s->plus != 1)) ? if_space(s, &(*r_f), 1) : 0;
	if ((s->width == 1) && (s->i_w > ((int)ft_strlen(s->str) + s->count_1)))
	{
		if (s->hyphen == 1)
			hyp_print(s, &(*r_f));
		else
			without_hyp_print(s, &(*r_f));
	}
	else
		print(s, &(*r_f));
}

void	ch_w(const char **r_form, va_list ap, t_uck *s)
{
	s->width = 1;
	while ((**r_form >= 49 && **r_form <= 57) || (**r_form == '*'))
	{
		if (**r_form >= 49 && **r_form <= 57)
		{
			s->i_w = ft_atoi(*r_form);
			while (ft_isdigit(**r_form))
				(*r_form)++;
		}
		else if (**r_form == '*')
		{
			s->i_w = va_arg(ap, int);
			(*r_form)++;
		}
	}
	if (s->i_w < 0)
	{
		s->i_w *= -1;
		s->hyphen = 1;
	}
}

void	ch_p(const char **r_form, va_list ap, t_uck *s)
{
	s->prec = 1;
	while (**r_form == '.')
		(*r_form)++;
	if (ft_isdigit(**r_form))
	{
		s->i_p = ft_atoi(*r_form);
		while (ft_isdigit(**r_form))
			(*r_form)++;
	}
	else if (**r_form == '*')
	{
		s->i_p = va_arg(ap, int);
		(*r_form)++;
	}
	else
		s->i_p = 0;
}
