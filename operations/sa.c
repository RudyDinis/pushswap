/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:37:52 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/22 12:10:00 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_swap_a(t_pile **p)
{
	t_pile	*tmp;
	int		first;
	int		second;

	if (ft_length(*p) <= 1)
		return (0);
	tmp = NULL;
	first = ft_pop(p);
	second = ft_pop(p);
	while (*p != NULL)
	{
		ft_push(&tmp, ft_pop(p));
	}
	ft_push(p, second);
	ft_push(p, first);
	while (tmp != NULL)
	{
		ft_push(p, ft_pop(&tmp));
	}
	write(1, "sa\n", 3);
	return (1);
}
