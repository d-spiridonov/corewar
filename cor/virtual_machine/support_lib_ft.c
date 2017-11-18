/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_lib_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 13:47:04 by yzakharc          #+#    #+#             */
/*   Updated: 2017/10/24 11:57:31 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		ft_intc(const int *mass, int c, int length)
{
	int	tmp;
	int	cnt;

	tmp = -1;
	cnt = 0;
	while (++tmp < length)
		if (mass[tmp] == c)
			cnt++;
	return (cnt);
}

int		*ft_intmalloc(size_t size)
{
	int	n;
	int	*tmp;

	n = -1;
	if (!(tmp = malloc(size * sizeof(tmp))))
		return (NULL);
	while (++n < (int)size)
		tmp[n] = 0;
	return (tmp);
}

int		len_value(int value)
{
	int i;

	i = 0;
	value < 0 ? i++ : 0;
	while (value != 0)
	{
		value /= 10;
		i++;
	}
	return (i);
}
