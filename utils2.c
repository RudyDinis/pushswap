/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:51:05 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/08 16:47:34 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*dec_to_binary(int n)
{
	int		index;
	char	*bin;
	int		bit;

	index = 0;
	bin = malloc(32 * sizeof(char));
	if (n == 0)
	{
		bin[index] = '0';
		bin[index + 1] = '\0';
		return (bin);
	}
	while (n > 0)
	{
		bit = n % 2;
		bin[index++] = '0' + bit;
		n /= 2;
	}
	bin[index] = '\0';
	return (bin);
}

int	find_bigger(t_pile *a)
{
	int	max;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = (a)-> next;
	}
	return (max);
}

void	*ft_calloc( size_t elementCount, size_t elementSize )
{
	unsigned char	*pointer;
	size_t			i;

	if (elementCount != 0 && elementSize > SIZE_MAX / elementCount)
		return (NULL);
	pointer = malloc(elementCount * elementSize);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < elementCount * elementSize)
	{
		pointer[i] = 0;
		i++;
	}
	return (pointer);
}

int	is_sorted(t_pile *a)
{
	while (a && a->next)
	{
		if (a->valeur > a->next->valeur)
			return (0);
		a = a->next;
	}
	return (1);
}
