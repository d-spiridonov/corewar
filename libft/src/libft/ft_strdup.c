/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:18:00 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 17:53:53 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		count;
	int		tot;

	tot = 0;
	count = 0;
	while (s1[count] != '\0')
		count++;
	if (!(s2 = (char *)malloc(sizeof(*s1) * (count + 1))))
		return (NULL);
	while (s1[tot] != '\0')
	{
		s2[tot] = s1[tot];
		tot++;
	}
	s2[tot] = '\0';
	return (s2);
}
