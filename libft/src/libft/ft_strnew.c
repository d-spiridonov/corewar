/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:30:48 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 17:59:22 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	count;
	char	*s;

	count = size;
	if (!(s = (char *)malloc((size + 1) * sizeof(*s))))
		return (NULL);
	while (size-- != 0)
		*s++ = '\0';
	*s = '\0';
	return (s - count);
}
