/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:27:17 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/06 14:54:17 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	append_node(t_stack **head, t_stack *node)
{
	t_stack	*tail;

	if (!head || !node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = node;
	node->prev = tail;
}

static t_stack	*to_stack(char **ag, int ac)
{
	int		i;
	t_stack	*a;
	t_stack	*node;
	long	value;

	i = 0;
	a = NULL;
	node = NULL;
	while (ag[i])
	{
		if (!is_int(ag[i]))
			error_exit(a, ag, ac);
		value = ft_atol(ag[i]);
		if (value < INT_MIN || value > INT_MAX)
			error_exit(a, ag, ac);
		node = create_node(value);
		if (!node)
			error_exit(a, ag, ac);
		if (!has_dup(a, value))
			error_exit(a, ag, ac);
		append_node(&a, node);
		i++;
	}
	return (a);
}

int	main(int ac, char **av)
{
	char	**ag;
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	if (ac == 2)
		ag = ft_split(av[1]);
	else
		ag = &av[1];
	a = to_stack(ag, ac);
	if (is_sorted(a))
		error_exit(a, ag, ac);
	assign_index(a);
	b = NULL;
	push_swap(&a, &b);
	free_stack(a);
	free_stack(b);
	if (ac == 2)
		free_split(ag);
	return (0);
}
