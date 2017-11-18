/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:55:13 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/08 15:44:17 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*d;

	if (*alst == NULL)
		return ;
	while (*alst)
	{
		d = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = d;
	}
}
