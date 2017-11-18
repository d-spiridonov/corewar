/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:25:04 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 18:25:05 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*d;

	if (!(d = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		d->content = NULL;
		d->content_size = 0;
	}
	else
	{
		if (!(d->content = (void *)malloc(sizeof(content) * content_size)))
			return (NULL);
		ft_memcpy(d->content, content, content_size);
		d->content_size = content_size;
	}
	d->next = NULL;
	return (d);
}
