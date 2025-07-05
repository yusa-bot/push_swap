/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:13:49 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:36:09 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
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

void	do_ra(t_stack **a)
{
	ra(a);
	ft_printf("ra\n");
}
