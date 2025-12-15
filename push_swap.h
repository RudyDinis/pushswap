/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:28:35 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/15 17:49:35 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct t_pile
{
	int				valeur;
	int				index;
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
void	ft_ra(t_pile **a);
int		ft_rb(t_pile **b);
int		ft_rr(t_pile **a, t_pile **b);
int		ft_rra(t_pile **a);
int		ft_rrb(t_pile **b);
int		ft_rrr(t_pile **a, t_pile **b);
char	*dec_to_binary(int n);
size_t	ft_strlen(const char *s);
void	ft_pa(t_pile **a, t_pile **b);
void	ft_pb(t_pile **a, t_pile **b);
int		find_bigger(t_pile *a);
char	**ft_split(const char *s, char c);
void	*ft_calloc( size_t elementCount, size_t elementSize );
int		word_count(const char *str, char c);
void	*free_(char **strs, int count, int start);
int		is_sorted(t_pile *a);
void	resolve2(t_pile **a, t_pile **b, int bit, int size);
void	resolve(t_pile **a, t_pile **b, int max);
int		find_min_pos(t_pile *a);
void	sort_5(t_pile **a, t_pile **b);
void	sort_3(t_pile **a);
void	sort_2(t_pile **a);
int		ft_lstsize(t_pile *a);

#endif