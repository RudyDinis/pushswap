/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:02:25 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/15 19:09:17 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p2(unsigned long long p)
{
	if (p >= 16)
	{
		ft_print_p2(p / 16);
		ft_print_p2(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar_fd((p + '0'), 1);
		else
			ft_putchar_fd((p - 10 + 'a'), 1);
	}
}

int	ft_get_len(unsigned long long p)
{
	int	len;

	len = 0;
	while (p >= 16)
	{
		p = p / 16;
		len++;
	}
	len++;
	return (len);
}

int	ft_printf_p(unsigned long long p)
{
	if (p == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	ft_print_p2(p);
	return (ft_get_len(p) + 2);
}

