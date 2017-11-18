/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:08:22 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 17:42:55 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*d;
	t_list	*new;

	d = f(lst);
	new = d;
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		d->next = f(lst);
		d = d->next;
	}
	return (new);
}
