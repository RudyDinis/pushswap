/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:05:38 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/08 11:25:00 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_pile **p, int val)
{
	t_pile	*element;
	t_pile	*temp;

	temp = *p;
	element = malloc(sizeof(t_pile));
	if (!element)
		ft_putstr_fd("Error", 2);
	element->valeur = val;
	element->next = NULL;
	if (!temp)
		*p = element;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = element;
	}
}

int	ft_pop(t_pile **p)
{
	int		val;
	t_pile	*tmp;

	if (!p)
		return (-1);
	tmp = (*p)->next;
	val = (*p)->valeur;
	free(*p);
	*p = tmp;
	return (val);
}

void	ft_clear(t_pile **p)
{
	t_pile	*tmp;

	while (*p)
	{
		tmp = (*p)->next;
		free(*p);
		*p = tmp;
	}
}

int	ft_length(t_pile *p)
{
	int	i;

	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void	ft_view(t_pile *p)
{
	while (p)
	{
		ft_putnbr_fd(p->valeur, 1);
		ft_putstr_fd(" : ", 1);
		ft_putnbr_fd(p->index, 1);
		ft_putstr_fd("\n", 1);
		p = p->next;
	}
}
