/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_validation_for_param.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 14:48:26 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/25 17:41:18 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		instruction_with_three_param1_1_1(t_labels *tmp, int i)
{
	if (!(check_registry(tmp, i, 0, 1)))
		return (0);
	skip_separator_between_param(tmp);
	if (!(check_registry(tmp, i, 1, 1)))
		return (0);
	skip_separator_between_param(tmp);
	return (check_registry(tmp, i, 2, -1));
}

int		instruction_with_three_param3_3_1(t_labels *tmp, int i)
{
	if (!(check_three(tmp, i, 0)))
		return (0);
	skip_separator_between_param(tmp);
	if (!(check_three(tmp, i, 1)))
		return (0);
	skip_separator_between_param(tmp);
	return (check_registry(tmp, i, 2, -1));
}

int		instruction_with_two_param2_1(t_labels *tmp, int i, int n)
{
	if (n == 1)
	{
		if (!(check_two(tmp, i, 2, 0)))
			return (0);
		skip_separator_between_param(tmp);
		return (check_registry(tmp, i, 1, -1));
	}
	else
	{
		if (!(check_registry(tmp, i, 0, 1)))
			return (0);
		skip_separator_between_param(tmp);
		return (check_two(tmp, i, 30, 1));
	}
}

int		instruction_with_three_param3_2_1(t_labels *tmp, int i)
{
	if (!(check_three(tmp, i, 0)))
		return (0);
	skip_separator_between_param(tmp);
	if (!(check_two_1(tmp, i, 2, 1)))
		return (0);
	skip_separator_between_param(tmp);
	return (check_registry(tmp, i, 2, -1));
}

int		instruction_with_three_param1_3_2(t_labels *tmp, int i)
{
	if (!(check_registry(tmp, i, 0, 1)))
		return (0);
	skip_separator_between_param(tmp);
	if (!(check_three(tmp, i, 1)))
		return (0);
	skip_separator_between_param(tmp);
	return (check_two_1(tmp, i, 20, 2));
}
