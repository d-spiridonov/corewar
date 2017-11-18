/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:51:21 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/15 11:21:31 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	len = len + 1;
	while (*big++ && len-- > 0 && ((ft_strlen(little) <= len) ||
	ft_strlen(little) == 0))
	{
		if ((ft_strncmp((big - 1), little, ft_strlen(little)) == 0))
			return ((char *)(big - 1));
	}
	return (NULL);
}
