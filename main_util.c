/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:05:26 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 19:01:01 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(const char *label, t_stack *stack)
{
	ft_printf("%s: ", label);
	while (stack)
	{
		ft_printf("[%d(i:%d)] ", stack->value, stack->index);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	free_split(char **ag)
{
	int	i;

	if (!ag)
		return ;
	i = 0;
	while (ag[i])
		free(ag[i++]);
	free(ag);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	error_exit(t_stack *a, char **ag, int ac)
{
	if (a)
		free_stack(a);
	if (ac == 2)
		free_split(ag);
	ft_printf("Error\n");
	exit(1);
}

void	assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
