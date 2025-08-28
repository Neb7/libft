/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:09:15 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 16:00:17 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Deletes and frees the given element and its content using the
 * 			function 'del'.
 * 
 * @param	lst The element to delete
 * @param	del The function to delete the content of the element
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst != NULL)
	{
		(*del)(lst->content);
		free(lst);
	}
}
