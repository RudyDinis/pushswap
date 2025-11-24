/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:26:51 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/24 19:13:16 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_bigger(t_pile **a)
{
	int	max;

	max = 0;
	while (*a)
	{
		if (*a > max)
			max = *a;
	}
	return (max);
}


int	init(char	**argv, t_pile **a)
{
	int	i;
	int	res;

	(void)argv;
	i = 1;
	while (argv[i])
	{
		res = ft_atoi(argv[i]);
		if (res == 0 && ft_strncmp(argv[i], "0", 1))
			return (-1);
		ft_push(a, res);
		i++;
	}
	return (1);
}

int	main(int argc, char	**argv)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (ft_putstr_fd("Error\n", 2));
	if (init(argv, &a) == -1)
		return (ft_putstr_fd("Error\n", 2));

	ft_swap_a(&a);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_rr(&a, &b);
	ft_rrr(&a, &b);
	ft_swap_a(&a);
	ft_pa(&a, &b);
	ft_pa(&a, &b);
	ft_pa(&a, &b);

	ft_view(a);
	printf("\n\n");
	ft_view(b);
}
