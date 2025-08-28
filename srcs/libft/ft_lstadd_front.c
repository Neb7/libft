/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:22:35 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 16:01:07 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Adds the element 'new' at the beginning of the list
 * 
 * @param	lst The address of the pointer to the head of the list
 * @param	new The element to add to the front of the list
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp_lst;

	if (!lst)
		return ;
	tmp_lst = *lst;
	if (tmp_lst)
		new->next = tmp_lst;
	*lst = new;
}
