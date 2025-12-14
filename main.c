/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:26:51 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/12 14:21:40 by rdinis           ###   ########.fr       */
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

int	assign_index(t_pile **a)
{
	t_pile	*current;
	t_pile	*tmp;
	int		index;
	int		doublon;

	current = *a;
	doublon = 0;
	while (current)
	{
		index = 0;
		tmp = *a;
		while (tmp)
		{
			if (tmp->valeur == current->valeur)
				doublon++;
			if (tmp->valeur < current->valeur)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
	return (doublon);
}

int	init(char	**argv, int argc, t_pile **a, int start)
{
	int	i;
	int	res;

	i = start;
	while (argv[i])
	{
		res = ft_atoi(argv[i]);
		if ((res < 0 && argv[i][0] != '-') || (res > 0 && argv[i][0] == '-'))
			return (-1);
		if (res == 0 && ft_strncmp(argv[i], "0", 1))
			return (-1);
		ft_push(a, res);
		i++;
	}
	if (assign_index(a) > argc)
		return (-1);
	return (1);
}

int	main(int argc, char	**arg)
{
	t_pile	*a;
	t_pile	*b;
	char	**argv;
	int		max;
	int		start;

	a = NULL;
	b = NULL;
	start = 1;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(arg[1], ' ');
		argc = word_count(arg[1], ' ');
		start = 0;
	}
	else
		argv = arg;
	if (init(argv, argc, &a, start) == -1)
		return (free_(argv, argc, start), ft_clear(&a), write(2, "Error\n", 6));
	max = find_bigger(a);
	resolve(&a, &b, max);
	free_(argv, argc, start);
	return (ft_clear(&a), 0);
}
