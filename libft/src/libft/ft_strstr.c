/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:57:20 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/15 11:24:40 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	while (*big++ || ft_strlen(little) == 0)
		if (ft_strncmp((big - 1), little, ft_strlen(little)) == 0)
			return ((char *)(big - 1));
	return (NULL);
}
