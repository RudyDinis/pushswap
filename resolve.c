/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:28:24 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/15 18:25:03 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve2(t_pile **a, t_pile **b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((((*a)->index >> bit) & 1) == 1)
			ft_ra(a);
		else
			ft_pb(a, b);
		i++;
	}
}

void	resolve(t_pile **a, t_pile **b, int max)
{
	int		max_bits;
	int		bit;
	int		size;
	t_pile	*tmp;

	if (is_sorted(*a))
		return ;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		size = 0;
		tmp = *a;
		while (tmp)
		{
			size++;
			tmp = tmp->next;
		}
		resolve2(a, b, bit, size);
		while (*b)
			ft_pa(a, b);
		bit++;
	}
}

void	sort_2(t_pile **a)
{
	if ((*a)->index > (*a)->next->index)
		ft_swap_a(a);
}

void	sort_3(t_pile **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->index;
	s = (*a)->next->index;
	t = (*a)->next->next->index;
	if (f > s && s < t && f < t)
		ft_swap_a(a);
	else if (f > s && s > t)
	{
		ft_swap_a(a);
		ft_rra(a);
	}
	else if (f > s && s < t && f > t)
		ft_ra(a);
	else if (f < s && s > t && f < t)
	{
		ft_swap_a(a);
		ft_ra(a);
	}
	else if (f < s && s > t && f > t)
		ft_rra(a);
}

void	sort_5(t_pile **a, t_pile **b)
{
	int	pos;

	while (ft_lstsize(*a) > 3)
	{
		pos = find_min_pos(*a);
		if (pos <= ft_lstsize(*a) / 2)
			while (pos--)
				ft_ra(a);
		else
			while (pos++ < ft_lstsize(*a))
				ft_rra(a);
		ft_pb(a, b);
	}
	sort_3(a);
	ft_pa(a, b);
	ft_pa(a, b);
}
