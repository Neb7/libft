/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:30:57 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 15:59:51 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Iterates the list 'lst' and applies the function 'f' to the content
 * 
 * @param	lst The head of the list
 * @param	f The function to apply to the content of each element
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_tmp;

	lst_tmp = lst;
	while (lst_tmp != NULL && f != NULL)
	{
		(*f)(lst_tmp->content);
		lst_tmp = lst_tmp->next;
	}
}
