/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:19:06 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 17:52:05 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
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
		ft_putchar_fd(s[f], fd);
		f++;
	}
	ft_putchar_fd('\n', fd);
}
