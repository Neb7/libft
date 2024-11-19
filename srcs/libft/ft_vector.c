/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:17:34 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/19 17:40:44 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_new_vector(void)
{
	t_vector	*new;

	new = (t_vector *)calloc(1, sizeof(t_vector));
	if (!new)
		return ((t_vector *) NULL);
	new->d = (char *)calloc(2, sizeof(char));
	if (!(new->d))
		return (free(new), (t_vector *) NULL);
	new->len = 0;
	new->max_len = 2;
	return (new);
}

t_vector	*ft_add_char_vector(char c, t_vector *vector)
{
	if (vector->len < vector->max_len)
	{
		vector->d[vector->len] = c;
		(vector->len)++;
	}
	else
	{
		vector = ft_double_len(vector);
		if (!vector)
			return ((t_vector *) NULL);
		vector->d[vector->len] = c;
		(vector->len)++;
	}
	return (vector);
}

t_vector	*ft_double_len(t_vector *vector)
{
	t_vector	*dbl;

	dbl = (t_vector *)malloc(sizeof(t_vector));
	if (!dbl)
		return (free(vector->d), free(vector), (t_vector *) NULL);
	dbl->d = (char *)malloc(sizeof(char) * (vector->max_len * 2));
	if (!(dbl->d))
		return (free(vector->d), free(vector), free(dbl), (t_vector *) NULL);
	ft_memcpy(dbl->d, vector->d, vector->max_len);
	dbl->len = vector->max_len;
	dbl->max_len = vector->max_len * 2;
	free(vector->d);
	free(vector);
	return (dbl);
}
