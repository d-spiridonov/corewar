/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:21:11 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 18:05:19 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	count;
	size_t	l;
	char	*d;

	count = 0;
	l = 0;
	if (!(s))
		return (NULL);
	i = ft_strlen(s);
	while (ft_isspace_s(s[count]) == 1)
		count++;
	if (count == i)
	{
		if (!(d = ft_strnew(0)))
			return (NULL);
		return (d);
	}
	i = i - 1;
	while (ft_isspace_s(s[i]) == 1)
		i--;
	if (!(d = ft_strnew(i - count + 1)))
		return (NULL);
	ft_strncpy(d, &s[count], (i - count + 1));
	return (d);
}
