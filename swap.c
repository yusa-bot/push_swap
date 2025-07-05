/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:12:20 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:36:09 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;
	int	tmp_inx;

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

void	do_sa(t_stack **a)
{
	sa(*a);
	ft_printf("sa\n");
}
