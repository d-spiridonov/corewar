/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:33:19 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 17:42:20 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*d;
	int		count;
	size_t	j;

	j = ft_countdigits(n);
	if (!(d = ft_strnew(j)))
		return (NULL);
	if (n == 0)
	{
		d[0] = 48;
		return (d);
	}
	if (n < 0)
		d[0] = '-';
	while (j - 1 > 0)
	{
		count = n % 10;
		if (count < 0)
			count = -count;
		d[j-- - 1] = count + 48;
		n /= 10;
	}
	if (n > 0)
		d[0] = n + 48;
	return (d);
}
