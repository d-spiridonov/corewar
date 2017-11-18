/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:13:43 by kzakharc          #+#    #+#             */
/*   Updated: 2016/12/12 17:53:02 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int count;

	count = 0;
	if (s == NULL)
		return ;
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
}
