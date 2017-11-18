/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:31:21 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 17:45:51 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *dest;

	dest = (unsigned char *)s;
	while (n--)
		if (*dest++ == (unsigned char)c)
			return (dest - 1);
	return (NULL);
}
