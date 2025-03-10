/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:44:12 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/29 10:52:23 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_all(t_buffer **start, t_buffer *tmp, t_buffer *tmp2, \
t_buffer *tmp3)
{
	bool		check;

	check = false;
	tmp3 = *start;
	if (tmp3 == tmp)
		check = true;
	else
		while (tmp3->next != tmp)
			tmp3 = tmp3->next;
	if (tmp != NULL)
	{
		tmp2 = tmp->next;
		free(tmp->vec->buf);
		free(tmp->vec);
		free(tmp);
	}
	tmp = *start;
	if (check)
		*start = tmp2;
	else
	{
		tmp3->next = tmp2;
	}
}
