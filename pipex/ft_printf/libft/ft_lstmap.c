/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:45:47 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/18 14:46:10 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*sec_link(t_list **link, void *content, void (*del)(void *))
{
	del(content);
	ft_lstclear(link, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*link;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	node = ft_lstnew(content);
	if (!node)
	{
		del(content);
		return (NULL);
	}
	link = node;
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
			return (sec_link(&link, content, del));
		ft_lstadd_back(&link, node);
		lst = lst->next;
	}
	return (link);
}

/*
 * t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*link;

	void	*content;


	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	node = ft_lstnew(content);
	if (!node)
	{
		del(content);
		return (NULL);
	}
		link = node;
	lst = lst->next;
	while (lst)
	{
		node = malloc(sizeof(t_list));

		if (!node)
		{
			ft_lstclear(&link, del);
			return (NULL);
		}
		node->next = 0;
		node->content = f(lst->content);
		ft_lstadd_back(&link, node);
		lst = lst->next;
	}
	return (link);
}
 */
