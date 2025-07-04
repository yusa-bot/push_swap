/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:09:27 by ayusa             #+#    #+#             */
/*   Updated: 2025/05/06 03:24:28 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;

	if (!*lst)
	{
		*lst = new;
		result ;
	}

	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
