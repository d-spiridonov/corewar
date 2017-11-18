/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:27:57 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 17:53:28 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr(char const *s)
{
	int count;

	count = 0;
	if (s == NULL)
		return ;
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
}
