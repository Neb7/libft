/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:46:11 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/21 11:04:43 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_tmp;

	lst_tmp = lst;
	if (lst == NULL)
		return (lst);
	while (lst_tmp->next != NULL)
		lst_tmp = lst_tmp->next;
	return (lst_tmp);
}
