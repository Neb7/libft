/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:20:12 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/15 16:01:39 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
