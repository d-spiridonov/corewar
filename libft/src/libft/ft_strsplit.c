/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:53:38 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/13 19:31:35 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char			**buf;
	unsigned int	i;
	size_t			k;
	size_t			t;

	i = 0;
	t = 0;
	if (s == NULL)
		return (NULL);
	if (!(buf = (char **)ft_memalloc(sizeof(char*) * (ft_cntwords(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if ((s[i] != c))
		{
			k = 0;
			while (s[i + k] != c && s[i + k])
				k++;
			if (!(buf[t++] = ft_strsub(s, i, k)))
				return (NULL);
			i += k - 1;
		}
		i++;
	}
	return (buf);
}
