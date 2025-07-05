/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:12:44 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 19:22:39 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	do_pb(t_stack **a, t_stack **b)
{
	pb(a, b);
	ft_printf("pb\n");
}

void	do_pa(t_stack **a, t_stack **b)
{
	pa(a, b);
	ft_printf("pa\n");
}
