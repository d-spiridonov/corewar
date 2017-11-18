/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:29:32 by kzakharc          #+#    #+#             */
/*   Updated: 2016/11/30 15:09:03 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*d;
	unsigned char	*s;

	count = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (count < n)
	{
		d[count] = s[count];
		count++;
	}
	return (d);
}
