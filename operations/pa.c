/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:25:57 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/22 13:25:57 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_pa(t_pile **b, t_pile **a)
{
	t_pile	*tmp;

	tmp = NULL;
	if (ft_length(*a) == 0)
		return (0);
	while (*b)
	{
		ft_push(&tmp, ft_pop(b));
	}
	ft_push(b, ft_pop(a));
	while (tmp)
	{
		ft_push(b, ft_pop(&tmp));
	}
	write(1, "pb\n", 3);
	return (1);
}