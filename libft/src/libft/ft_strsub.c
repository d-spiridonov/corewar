/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:59:34 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/13 19:31:00 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_strnew(len)))
		return (NULL);
	if (s == NULL)
		return (NULL);
	ft_memcpy(tmp, s + start, len);
	return (tmp);
}
