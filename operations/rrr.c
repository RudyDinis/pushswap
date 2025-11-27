/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:01:50 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/25 14:38:59 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(t_pile **a)
{
	t_pile	*tmp;

	tmp = NULL;
	while (ft_length(*a) != 1)
		ft_push(&tmp, ft_pop(a));
	while (tmp)
		ft_push(a, ft_pop(&tmp));
	return (1);
}

int	rrb(t_pile **b)
{
	t_pile	*tmp;

	tmp = NULL;
	while (ft_length(*b) != 1)
		ft_push(&tmp, ft_pop(b));
	while (tmp)
		ft_push(b, ft_pop(&tmp));
	return (1);
}

int	ft_rrr(t_pile **a, t_pile **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
	return (1);
}
