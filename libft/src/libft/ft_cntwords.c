/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:17:39 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 19:21:15 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cntwords(char const *str, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if (str == 0)
		return (0);
	while (str[count] == c)
		count++;
	while (str[count])
	{
		while (str[count] != c && str[count])
			count++;
		i++;
		while (str[count] == c && str[count])
			count++;
	}
	return (i);
}
