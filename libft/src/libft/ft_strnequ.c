/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:22:44 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/13 19:04:49 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t count;

	count = 0;
	while (s1 && s2 && (count < n))
	{
		if (s1[count] == s2[count])
			count++;
		else
			return (0);
	}
	return (1);
}
