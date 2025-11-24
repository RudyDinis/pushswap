/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:28:35 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/24 19:04:16 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_pile
{
	int				valeur;
	struct t_pile	*next;
}	t_pile;

int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *src);
void	ft_push(t_pile **p, int val);
int		ft_pop(t_pile **p);
void	ft_view(t_pile *p);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_length(t_pile *p);
void	ft_clear(t_pile **p);
int		ft_swap_a(t_pile **p);
int		ft_swap_b(t_pile **p);
int		ft_ss(t_pile **a, t_pile **b);
int		ft_pb(t_pile **a, t_pile **b);
int		ft_pa(t_pile **b, t_pile **a);
int		ft_ra(t_pile **a);
int		ft_rb(t_pile **b);
int		ft_rr(t_pile **a, t_pile **b);
int		ft_rra(t_pile **a);
int		ft_rrb(t_pile **b);
int		ft_rrr(t_pile **a, t_pile **b);

#endif