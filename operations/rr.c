/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:53:35 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/24 18:54:18 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_pile **a)
{
	ft_push(a, ft_pop(a));
	return (1);
}

int	rb(t_pile **b)
{
	ft_push(b, ft_pop(b));
	return (1);
}

int	ft_rr(t_pile **a, t_pile **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
	return (1);
}
