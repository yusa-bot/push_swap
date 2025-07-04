/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:29:39 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/04 20:58:40 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int tmp;
	int tmp_inx;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;

	tmp_inx = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp_inx;
}

void	sb(t_stack *stack)
{
	sa(stack);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;

	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;

	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	tmp->prev = NULL;
	*a = tmp;
}

void	pb(t_stack **a, t_stack **b)
{
	pa(b, a);
}

void	ra(t_stack **stack)
{
	t_stack *tmp;
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return ;

	tmp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;//ここまでで初期セット

	*stack = tmp->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;//元の先頭を操作
	tmp->prev = last;
	last->next = tmp;
}

void	rb(t_stack **stack)
{
	ra(stack);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack **stack)
{
	t_stack *last;
	t_stack *before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;

	last = *stack;
	while (last->next)
		last = last->next;

	before_last = last->prev;
	before_last->next = NULL;

	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;

	*stack = last;
}

void	rrb(t_stack **stack)
{
	rra(stack);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
