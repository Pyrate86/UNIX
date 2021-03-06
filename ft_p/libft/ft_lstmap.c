/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 17:34:21 by ghilbert          #+#    #+#             */
/*   Updated: 2015/06/06 17:45:17 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmp;
	t_list	*newlst2;

	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		tmp = f(lst);
		if (newlst == NULL)
		{
			if (!(newlst = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			lst = lst->next;
			newlst2 = newlst;
		}
		else
		{
			if (!(newlst->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			newlst = newlst->next;
			lst = lst->next;
		}
	}
	return (newlst2);
}
