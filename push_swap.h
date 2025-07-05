/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:19:50 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 20:16:45 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	print_stack(const char *label, t_stack *stack);
int		is_int(char *str);
void	error_exit(t_stack *a, char **ag, int ac);
int		has_dup(t_stack *stack, int value);
int		is_sorted(t_stack *stack);
void	assign_index(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_split(char **ag);

void	push_swap(t_stack **a, t_stack **b);
void	radix(t_stack **a, t_stack **b, int size);
t_stack	*get_min_node(t_stack *stack);
int		get_pos(t_stack *stack, t_stack *min);

void	pos_ra(t_stack **a, t_stack *min);
void	pos_rra(t_stack **a, t_stack *min);

void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **a, t_stack **b);
void	do_ra(t_stack **a);

void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **a, t_stack **b);
void	do_rra(t_stack **a);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	do_sa(t_stack **a);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	do_pb(t_stack **a, t_stack **b);
void	do_pa(t_stack **a, t_stack **b);

void	zyx(t_stack **a);
void	xzy(t_stack **a);

#endif
