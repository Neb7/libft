/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:29:12 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/15 16:02:03 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*lst_tmp;

	count = 0;
	lst_tmp = lst;
	if (lst == NULL)
		return (count);
	while (lst_tmp != NULL)
	{
		count++;
		lst_tmp = lst_tmp->next;
	}
	return (count);
}
