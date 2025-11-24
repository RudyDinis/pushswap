/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:24:17 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/22 12:41:21 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap_a(t_pile **p)
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
	return (1);
}

int	swap_b(t_pile **p)
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
	return (1);
}

int	ft_ss(t_pile **a, t_pile **b)
{
	if (swap_a(a) == 1 || swap_a(b) == 1)
	{
		write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}
