/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:26:51 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/15 18:23:37 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		{
			return (-1);
		}
		ft_push(a, res);
		i++;
	}
	if (assign_index(a) > argc)
		return (-1);
	return (1);
}

void	choose_resolve(t_pile **a, t_pile **b, int max)
{
	if (max == 2)
		return (resolve_simple(a, b, max));
	resolve(a, b, max);
}

int	argc_two(t_pile **a, t_pile **b, char	**arg)
{
	char	**argv;
	int		argc;
	int		max;

	argv = ft_split(arg[1], ' ');
	argc = word_count(arg[1], ' ');
	if (init(argv, argc, a, 0) == -1)
		return (free_(argv, argc, 0), ft_clear(a), write(2, "Error\n", 6));
	max = find_bigger(*a);
	return (choose_resolve(a, b, max), free_(argv, argc, 0), ft_clear(a), 0);
}

int	main(int argc, char	**arg)
{
	t_pile	*a;
	t_pile	*b;
	char	**argv;
	int		max;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		return (argc_two(&a, &b, arg));
	argv = arg;
	if (init(argv, argc, &a, 1) == -1)
		return (free_(argv, argc, 1), ft_clear(&a), write(2, "Error\n", 6));
	max = find_bigger(a);
	return (choose_resolve(&a, &b, max), free_(argv, argc, 1), ft_clear(&a), 0);
}
