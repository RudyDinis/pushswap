/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:13:31 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/15 17:19:40 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	if (fd == 2)
		return (-1);
	return (1);
}

size_t	get_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putnbr_fd((n % 10), fd);
		}
		else
		{
			c = n + 48;
			write(fd, &c, 1);
		}
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *src)
{
	int	i;
	int	signe;
	int	res;

	i = 0;
	signe = 1;
	res = 0;
	while (src[i] == '\t' || src[i] == '\n'
		|| src[i] == ' ' || src[i] == '\v' || src[i] == '\f' || src[i] == '\r')
		i++;
	while (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-')
			signe = signe * -1;
		if (src[i + 1] == '-' || src[i + 1] == '+')
			return (0);
		i++;
	}
	while (src[i])
	{
		if (!(src[i] >= '0' && src[i] <= '9'))
			return (0);
		res = res * 10 + (src[i++] - 48);
	}
	return (signe * res);
}
