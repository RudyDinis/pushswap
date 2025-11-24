/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:01:58 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/15 19:02:18 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	send(va_list args, char type)
{
	int	res;

	res = 0;
	if (type == 'c')
		res += ft_putchar_fd(va_arg(args, int), 1);
	else if (type == 'd' || type == 'i')
		res += print_number(va_arg(args, int));
	else if (type == 's')
		res += ft_putstr_fd(va_arg(args, char *), 1);
	else if (type == '%')
		res += print_percent();
	else if (type == 'p')
		res += ft_printf_p(va_arg(args, unsigned long long));
	else if (type == 'u')
		res += ft_print_unsigned(va_arg(args, unsigned int));
	else if (type == 'x')
		res += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (type == 'X')
		res += ft_print_hex_upper(va_arg(args, unsigned int));
	return (res);
}

int	ft_printf(const char	*str, ...)
{
	va_list	args;
	int		i;
	int		res;

	va_start(args, str);
	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			res += send(args, str[i + 1]);
			i++;
		}
		else
			res += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (res);
}
