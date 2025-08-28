/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:54:56 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 16:01:17 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Adds the element 'new' at the end of the list
 * 
 * @param	lst The address of the pointer to the head of the list
 * @param	new The element to add to the end of the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_tmp;

	if (!lst)
		return ;
	lst_tmp = *lst;
	if (!lst_tmp)
	{
		*lst = new;
		return ;
	}
	while (lst_tmp->next != NULL)
		lst_tmp = lst_tmp->next;
	lst_tmp->next = new;
}
