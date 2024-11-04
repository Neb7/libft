/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:41:25 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/21 11:48:03 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_new_lst;
	t_list	*new_elem;
	t_list	*lst_tmp;
	void	*content_tmp;

	lst_tmp = lst;
	begin_new_lst = NULL;
	if (!f || !del)
		return (NULL);
	while (lst_tmp)
	{
		content_tmp = (*f)(lst_tmp->content);
		new_elem = ft_lstnew(content_tmp);
		if (! new_elem)
		{
			(*del)(content_tmp);
			ft_lstclear(&begin_new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&begin_new_lst, new_elem);
		lst_tmp = lst_tmp->next;
	}
	return (begin_new_lst);
}
