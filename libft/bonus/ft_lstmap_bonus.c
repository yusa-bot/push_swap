/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 04:03:54 by ayusa             #+#    #+#             */
/*   Updated: 2025/05/08 17:58:16 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
//{
//	t_list	*new_list;
//	t_list	*new_node;
//	void	*new_content;

//	if (!lst || !f || !del)
//		return (NULL);
//	new_list = NULL;
//	while (lst)
//	{
//		new_content = f(lst->content);
//		new_node = ft_lstnew(new_content);
//		if (!new_node)
//		{
//			ft_lstclear(&new_node, del);
//			return (NULL);
//		}
//		ft_lstadd_back(&new_list, new_node);
//		lst = lst->next;
//	}
//	return (new_list);
//}

#include <ft_lst.h>
#include <stddef.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	new_lst = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
