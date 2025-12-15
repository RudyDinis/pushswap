/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:51:05 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/08 16:47:34 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_pile *a)
{
	int	pos;
	int	i;
	int	min;

	pos = 0;
	i = 0;
	min = a->index;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

int	ft_lstsize(t_pile *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}
