/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:22:47 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/24 18:53:25 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rra(t_pile **a)
{
	t_pile	*tmp;

	tmp = NULL;
	while (ft_length(*a) != 1)
		ft_push(&tmp, ft_pop(a));
	while (tmp)
		ft_push(a, ft_pop(&tmp));
	write(1, "rra\n", 4);
	return (1);
}
