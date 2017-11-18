/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:00:42 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/02 14:28:04 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int count;
	int c;

	count = 0;
	c = 0;
	while (s1[count] != '\0')
		count++;
	while (s2[c] != '\0')
	{
		s1[count] = s2[c];
		count++;
		c++;
	}
	s1[count] = '\0';
	return (s1);
}
