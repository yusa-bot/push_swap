/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5_6_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:10:36 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:36:09 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_ra(t_stack **a, t_stack *min)
{
	while (*a != min)
	{
		ra(a);
		ft_printf("ra\n");
	}
}

void	pos_rra(t_stack **a, t_stack *min)
{
	while (*a != min)
	{
		rra(a);
		ft_printf("rra\n");
	}
}

t_stack	*get_min_node(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (min->value > stack->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	get_pos(t_stack *stack, t_stack *min)
{
	int	pos;

	pos = 0;
	if (!stack || !min)
		return (0);
	while (stack)
	{
		if (stack == min)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}
