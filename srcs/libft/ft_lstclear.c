/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:20:12 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 16:00:24 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Deletes and frees the entire list starting from 'lst' using the
 * 			function 'del' and sets the pointer to the list to NULL.
 * 
 * @param	lst The address of the pointer to the head of the list
 * @param	del The function to delete the content of each element
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_tmp;
	t_list	*tmp;

	if (!lst)
		return ;
	lst_tmp = *lst;
	while (lst_tmp != NULL)
	{
		tmp = lst_tmp;
		lst_tmp = lst_tmp->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
