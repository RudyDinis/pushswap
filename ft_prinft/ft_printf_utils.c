/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:06:58 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/15 19:01:45 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_print_unsigned(unsigned int number)
{
	int	len;

	len = 0;
	if (number >= 10)
		len += ft_print_unsigned(number / 10);
	len += ft_putchar_fd((number % 10) + '0', 1);
	return (len);
}

int	ft_print_hex_lower(unsigned int n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += ft_print_hex_lower(n / 16);

	len += ft_putchar_fd(base[n % 16], 1);
	return (len);
}

int	ft_print_hex_upper(unsigned int n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_print_hex_upper(n / 16);

	len += ft_putchar_fd(base[n % 16], 1);
	return (len);
}

int	print_number(int number)
{
	int		len;
	char	*num;

	num = ft_itoa(number);
	len = ft_putstr_fd(num, 1);
	free(num);
	return (len);
}
