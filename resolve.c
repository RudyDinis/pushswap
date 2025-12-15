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

void	resolve_simple(t_pile **a, t_pile **b, int max)
{
	t_pile	*tmp;
	int		i;

	(void) b;
	i = 0;
	while (i != max)
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->index == i)
			{
				ft_rra(a);
				i++;
				ft_view(*a);
				break ;
			}
			tmp = tmp ->next;
		}
	}
}
