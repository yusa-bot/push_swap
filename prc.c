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
