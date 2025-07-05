/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:15:21 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:47:01 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_size(t_stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

static void	sort_2(t_stack *a)
{
	if (a->value > a->next->value)
	{
		sa(a);
		ft_printf("sa\n");
	}
}

static void	sort_3(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x < y && y < z)
		return ;
	else if (x > y && y < z && x < z)
		do_sa(a);
	else if (x > y && y > z && x > z)
		zyx(a);
	else if (x > y && y < z && x > z)
		do_ra(a);
	else if (x < y && y > z && x < z)
		xzy(a);
	else if (x < y && y > z && x > z)
		do_rra(a);
}

static void	sort_4_5_6(t_stack **a, t_stack **b, int size)
{
	t_stack	*min;
	int		pos;

	while (size > 3)
	{
		min = get_min_node(*a);
		pos = get_pos(*a, min);
		if (pos <= size / 2)
			pos_ra(a, min);
		else
			pos_rra(a, min);
		pb(a, b);
		ft_printf("pb\n");
		size--;
	}
	sort_3(a);
	while (*b)
		do_pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 1)
		return ;
	if (size == 2)
		sort_2(*a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 6)
		sort_4_5_6(a, b, size);
	else if (size >= 7)
		radix(a, b, size);
}
