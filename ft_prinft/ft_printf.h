/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:07:25 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/15 19:01:58 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int	ft_printf(const char	*str, ...);
int	print_percent(void);
int	print_number(int number);
int	ft_printf_p(unsigned long long p);
int	ft_print_unsigned(unsigned int number);
int	ft_print_hex_lower(unsigned int n);
int	ft_print_hex_upper(unsigned int n);

#endif