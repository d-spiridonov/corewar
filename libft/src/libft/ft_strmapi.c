/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:05:37 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/02 21:16:57 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char*d;
	int count;

	count = 0;
	if (s)
	{
		d = ft_strnew(ft_strlen(s));
		if (d == 0)
			return (NULL);
		while (s[count])
		{
			d[count] = f(count, s[count]);
			count++;
		}
		return (d);
	}
	return (NULL);
}
