/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:30:57 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/15 16:01:46 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
