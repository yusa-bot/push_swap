/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:27:17 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/04 20:11:42 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_int(char *str)
{
	int i = 0;
	int sign = 0;
	if (!str || str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_stack *create_node(int value)
{
	t_stack *node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	append_node(t_stack **head, t_stack *node)
{
	t_stack *tail;

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

int	has_dup(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void free_stack(t_stack *stack)
{
	t_stack *tmp;
	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void free_split(char **ag)
{
	int	i;

	if (!ag)
		return ;
	i = 0;
	while (ag[i])
		free(ag[i++]);
	free(ag);
}

void	assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack *compare;
	int index;

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
//
void	print_stack(const char *label, t_stack *stack)
{
	printf("%s: ", label);
	while (stack)
	{
		printf("[%d(i:%d)] ", stack->value, stack->index);
		stack = stack->next;
	}
	printf("\n");
}

int main(int ac, char **av)
{
	int num = 0;
	int i = 0;
	char **ag;

	if (ac == 1)
		return (0);
	if (ac == 2)
		ag  = ft_split(av[1], ' ');
	else
		ag = &av[1];


	t_stack	*a = NULL;
	t_stack *node = NULL;
	while (ag[i])
	{
		if (!is_int(ag[i]))
			return printf("Error\n");

		int value = atoi(ag[i]);
		node = create_node(value);
		if (!node)
			return printf("Error\n");
		if (!has_dup(a, value))
			return printf("Error\n");
		append_node(&a, node);
		i++;
	}
	assign_index(a);
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}

	t_stack *b = NULL;

	//print_stack("A", a);
	//print_stack("B", b);

	push_swap(&a, &b);

	//print_stack("A", a);
	//print_stack("B", b);

	free_stack(a);
	free_stack(b);
	if (ac == 2)
		free_split(ag);
}
