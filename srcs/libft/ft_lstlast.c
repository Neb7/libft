/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:46:11 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/15 16:01:49 by benpicar         ###   ########.fr       */
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
