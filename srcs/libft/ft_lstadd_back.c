/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:54:56 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/15 16:01:32 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
