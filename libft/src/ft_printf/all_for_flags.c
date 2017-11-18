/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_for_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:50:02 by kzakharc          #+#    #+#             */
/*   Updated: 2017/06/14 19:17:00 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	if_hash(t_uck *s, const char **r_f, int i)
{
	if (i == 0)
	{
		((**r_f == 'x') || (**r_f == 'p')) ? (ft_putstr("0x")) : 0;
		(**r_f == 'X') ? (ft_putstr("0X")) : 0;
		((**r_f == 'o') || (**r_f == 'O')) ? (ft_putstr("0")) : 0;
		if ((**r_f == 'x') || (**r_f == 'X') || (**r_f == 'p'))
			s->count += 2;
		else
			s->count += 1;
		s->has = 0;
	}
	if (i == 1)
	{
		if ((**r_f == 'x') || (**r_f == 'X') || (**r_f == 'p'))
			s->count_1 += 2;
		else
			s->count_1 += 1;
	}
}

void	if_plus(t_uck *s, const char **r_f, int i)
{
	if (i == 0)
	{
		if ((s->str[0] != '-') && ((**r_f != 's') || (**r_f != 'S')))
		{
			ft_putchar('+');
			s->count += 1;
		}
	}
	if (i == 1)
		s->count_1 += 1;
}

void	if_space(t_uck *s, const char **r_f, int i)
{
	if (i == 0)
	{
		if ((s->str[0] != '-') && ((**r_f != 's') || (**r_f != 'S')))
		{
			ft_putchar(' ');
			s->count += 1;
		}
	}
	if (i == 1)
		s->count_1 += 1;
}

char	*get_memory(int size, t_uck *s, int i)
{
	char *tmp;
	char *dst;

	tmp = malloc(sizeof(char) * (size + 1));
	dst = tmp;
	if (i != 0)
		dst = ft_strcpy(dst, s->str);
	free(tmp);
	return (dst);
}
