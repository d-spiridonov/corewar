/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:40:41 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 17:44:45 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			count;
	unsigned char	*s;

	count = size;
	if (!(s = (void *)malloc(size * sizeof(s))))
		return (NULL);
	while (size-- != 0)
		*s++ = 0;
	return (s - count);
}
