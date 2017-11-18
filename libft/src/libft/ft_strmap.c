/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:35:41 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 17:57:22 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	int		count;

	count = 0;
	if (s)
	{
		d = ft_strnew(ft_strlen(s));
		if (d == 0)
			return (NULL);
		while (s[count])
		{
			d[count] = f(s[count]);
			count++;
		}
		return (d);
	}
	return (NULL);
}
