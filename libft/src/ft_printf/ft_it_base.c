/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:12:02 by kzakharc          #+#    #+#             */
/*   Updated: 2017/06/13 21:38:57 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int				count(intmax_t value, int base)
{
	int	i;

	i = 0;
	if ((value <= 0) && base == 10)
		i++;
	while (value != 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}

int				count_c(uintmax_t value, int base)
{
	int i;

	i = 0;
	while (value != 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}

char			*ft_b(intmax_t value, int base)
{
	int			a;
	intmax_t	b;
	char		*str;

	a = count(value, base);
	str = (char *)malloc(sizeof(char) * (a + 1));
	str[a] = '\0';
	if (value == 0)
	{
		str[0] = '0';
		return (str);
	}
	if ((value < 0) && base == 10)
		str[0] = '-';
	while (value != 0)
	{
		b = value % base;
		if (b < 0)
			b = -b;
		if (b > 9)
			b += 7;
		str[a-- - 1] = (char)(b + 48);
		value = value / base;
	}
	return (str);
}

char			*i(uintmax_t value, int base, int flag)
{
	int			a;
	uintmax_t	b;
	char		*str;

	a = count_c(value, base);
	str = (char *)malloc(sizeof(char) * (a + 1));
	str[a] = '\0';
	if (value == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (value != 0)
	{
		b = value % base;
		if (b > 9 && flag == 2)
			b += 7;
		else if (b > 9 && flag == 1)
			b += 39;
		str[a-- - 1] = (char)(b + 48);
		value /= base;
	}
	return (str);
}
