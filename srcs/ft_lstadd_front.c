/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:22:35 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/27 11:57:57 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
