/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:53:23 by yzakharc          #+#    #+#             */
/*   Updated: 2017/03/21 20:20:08 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	**ft_check_fd(const int fd, t_line **head)
{
	t_line *tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (&(tmp->str));
		tmp = tmp->next;
	}
	tmp = (t_line *)malloc(sizeof(t_line));
	tmp->fd = fd;
	tmp->str = ft_strnew(0);
	tmp->next = (*head);
	(*head) = tmp;
	return (&(tmp->str));
}

static int	ft_check(char *str, int *i)
{
	int j;

	j = 0;
	while (*str)
	{
		if (j != 1)
			(*str != '\n') ? (*i)++ : (j = 1);
		str++;
	}
	j = (*str == '\0') ? 1 : 0;
	return (j);
}

static void	ft_cat_str(char **str, int i)
{
	int n;

	n = -1;
	while ((*str)[i] && **str)
		(*str)[++n] = (*str)[++i];
}

static int	ft_write(char **str, char **line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (ft_check(*str, &i))
	{
		*line = ft_strsub(*str, 0, (size_t)i);
		if (i == (int)ft_strlen(*str))
		{
			tmp = *str;
			*str = ft_strnew(0);
			free(tmp);
		}
	}
	if ((**str && **line) || (!**line && **str == '\n') || (**line && !**str))
		j = 1;
	ft_cat_str(str, i);
	return (j);
}

int			get_next_line(const int fd, char **line)
{
	char			**str;
	char			*temp;
	ssize_t			r_res;
	static t_line	*head;
	char			*dump;

	temp = ft_strnew(BUFF_SIZE);
	if (((read(fd, temp, 0)) < 0) || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	str = ft_check_fd(fd, &head);
	while ((r_res = read(fd, temp, BUFF_SIZE)) > 0)
	{
		dump = *str;
		*str = ft_strjoin(dump, temp);
		ft_strdel(&dump);
		if (ft_strchr(*str, '\n'))
			break ;
		ft_strclr(temp);
	}
	ft_strdel(&temp);
	if (r_res == 0 && !ft_strlen(*str))
		return (0);
	return (ft_write(&(*str), line));
}
