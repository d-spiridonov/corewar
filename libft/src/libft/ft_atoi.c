/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:29:02 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/15 12:34:09 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_atoi(const char *str)
{
	long int	b;
	long int	d;

	b = 0;
	while (ft_isspace(*str) == 1)
		str++;
	d = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		b = b * 10 + (*str - '0');
		str++;
	}
	return (b * d);
}
