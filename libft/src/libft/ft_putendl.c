/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:01:26 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 17:49:31 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int count;
	int f;

	count = 0;
	f = 0;
	if (s == NULL)
		return ;
	while (s[count] != '\0')
		count++;
	while (f < count)
	{
		ft_putchar(s[f]);
		f++;
	}
	ft_putchar('\n');
}
