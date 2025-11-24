/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:54:35 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/24 18:54:54 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rrb(t_pile **b)
{
	t_pile	*tmp;

	tmp = NULL;
	while (ft_length(*b) != 1)
		ft_push(&tmp, ft_pop(b));
	while (tmp)
		ft_push(b, ft_pop(&tmp));
	write(1, "rrb\n", 4);
	return (1);
}
