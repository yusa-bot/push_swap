/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:15:21 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/04 19:29:49 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *a)
{
	int i;

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

void sort_2(t_stack *a)
{
	if (a->value > a->next->value)
	{
		sa(a);
		printf("sa\n");
	}
}

void sort_3(t_stack **a)
{
	int x = (*a)->value;
	int y = (*a)->next->value;
	int z = (*a)->next->next->value;

	if (x < y && y < z)
		return ;
	else if (x > y && y < z && x < z)
	{
		sa(*a);
		printf("sa\n");
	}
	else if (x > y && y > z && x > z)
	{
		sa(*a);
		printf("sa\n");
		rra(a);
		printf("rra\n");
	}
	else if (x > y && y < z && x > z)
	{
		ra(a);
		printf("ra\n");
	}
	else if (x < y && y > z && x < z)
	{
		sa(*a);
		printf("sa\n");
		ra(a);
		printf("ra\n");
	}
	else if (x < y && y > z && x > z)
	{
		rra(a);
		printf("rra\n");
	}
}

t_stack *get_min_node(t_stack *stack)
{
	t_stack *min;
	int pos;

	pos = 0;
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

int get_pos(t_stack *stack, t_stack *min)
{
	int pos;

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
//6か？
void	sort_4_5(t_stack **a, t_stack **b, int size)
{
	t_stack *min;
	int pos;

	while (size > 3)
	{
		min = get_min_node(*a);
		pos = get_pos(*a, min);

		if (pos <= size / 2)
		{
			while (*a != min)
			{
				ra(a);
				printf("ra\n");
			}
		}
		else
		{
			while (*a != min)
			{
				rra(a);
				printf("rra\n");
			}
		}
		pb(a, b);
		printf("pb\n");
		size--;
	}
	sort_3(a);
	while (*b)
	{
		pa(a, b);
		printf("pa\n");
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int size = stack_size(*a);

	if (size == 1)
		return ;
	if (size == 2)
		sort_2(*a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 6)//OK
		sort_4_5(a, b, size);
	else if (size >= 7)
		radix(a, b, size);
}
