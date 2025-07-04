/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:15:25 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/04 20:52:51 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stack **a, t_stack **b, int size)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	//printf("%d", max_bits);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i & 1))
			{
				ra(a);
				printf("ra\n");
			}
			else
			{
				pb(a, b);
				printf("pb\n");
			}
			j++;
		}
		while (*b)
		{
			pa(a,b);
			printf("pa\n");
		}
		i++;
	}
}
