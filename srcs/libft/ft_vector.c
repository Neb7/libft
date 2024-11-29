/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:17:34 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/28 10:24:57 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_new_vector(void)
{
	t_vector	*new;

	new = (t_vector *)ft_calloc(1, sizeof(t_vector));
	if (!new)
		return ((t_vector *) NULL);
	new->buf = (char *)ft_calloc(2, sizeof(char));
	if (!(new->buf))
		return (free(new), (t_vector *) NULL);
	new->index = 0;
	new->max_len = 2;
	return (new);
}

t_vector	*ft_add_char_vector(char *s, t_vector *vector, size_t len)
{
	char	*dbl;

	if (vector->index + len <= vector->max_len)
	{
		ft_memcpy(&vector->buf[vector->index], s, len);
		vector->index = vector->index + len;
	}
	else
	{
		dbl = (char *)malloc(sizeof(char) * ((vector->max_len * 2) + len));
		if (!(dbl))
			return ((t_vector *) NULL);
		ft_memcpy(dbl, vector->buf, vector->max_len);
		vector->max_len = (vector->max_len * 2) + len;
		free(vector->buf);
		vector->buf = dbl;
		ft_memcpy(&vector->buf[vector->index], s, len);
		vector->index = vector->index + len;
	}
	return (vector);
}

void	ft_free_vector(t_vector **vector)
{
	free((*vector)->buf);
	free(*vector);
	*vector = NULL;
}
