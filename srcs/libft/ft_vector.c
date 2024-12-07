/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:17:34 by benpicar          #+#    #+#             */
/*   Updated: 2024/12/04 14:38:26 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_new_vector(size_t nb_octect)
{
	t_vector	*new;

	new = (t_vector *)ft_calloc(1, sizeof(t_vector));
	if (!new)
		return ((t_vector *) NULL);
	new->buf = (void *)ft_calloc(2, nb_octect);
	if (!(new->buf))
		return (free(new), (t_vector *) NULL);
	new->index = 0;
	new->max_len = 2;
	return (new);
}

t_vector	*ft_add_char_vector(void *s, t_vector *vector, size_t len, \
size_t nb_octect)
{
	void	*dbl;

	if (vector->index + len <= vector->max_len)
	{
		ft_memcpy(vector->buf + (vector->index * nb_octect), s, \
		len * nb_octect);
		vector->index = vector->index + len;
	}
	else
	{
		dbl = (void *)malloc(nb_octect * ((vector->max_len * 2) + len));
		if (!(dbl))
			return ((t_vector *) NULL);
		ft_memcpy(dbl, vector->buf, vector->index * nb_octect);
		vector->max_len = (vector->max_len * 2) + len;
		free(vector->buf);
		vector->buf = (void *)dbl;
		ft_memcpy(vector->buf + (vector->index * nb_octect), s, \
		len * nb_octect);
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

char	*ft_vtos(t_vector	*vector)
{
	char	*d;

	d = (char *)malloc(sizeof(char) * (vector->index + 1));
	if (!d)
		return (NULL);
	ft_memcpy(d, vector->buf, vector->index);
	d[vector->index] = 0;
	return (d);
}

/*t_vector	*ft_add_char_vector(char *s, t_vector *vector, size_t len)
{
	char	*dbl;

	if (vector->index + len <= vector->max_len)
	{
		ft_memcpy(&((char *)vector->buf)[vector->index], s, len);
		vector->index = vector->index + len;
	}
	else
	{
		dbl = (char *)malloc((vector->max_len * 2) + len);
		if (!(dbl))
			return ((t_vector *) NULL);
		ft_memcpy(dbl, (char *)vector->buf, vector->index);
		vector->max_len = (vector->max_len * 2) + len;
		free(vector->buf);
		vector->buf = (void *)dbl;
		ft_memcpy(&((char *)vector->buf)[vector->index], s, len);
		vector->index = vector->index + len;
	}
	return (vector);
}
t_vector	*ft_add_uint_vector(unsigned int *s, t_vector *vector, size_t len)
{
	unsigned int	*dbl;

	if (vector->index + len <= vector->max_len)
	{
		ft_memcpy(&((unsigned int *)vector->buf)[vector->index], s, \
		len * sizeof(unsigned int));
		vector->index = vector->index + len;
	}
	else
	{
		dbl = (unsigned int *)malloc(sizeof(unsigned int) * \
		((vector->max_len * 2) + len));
		if (!(dbl))
			return ((t_vector *) NULL);
		ft_memcpy(dbl, (unsigned int *)vector->buf, \
		vector->index * sizeof(unsigned int));
		vector->max_len = (vector->max_len * 2) + len;
		free(vector->buf);
		vector->buf = (void *)dbl;
		ft_memcpy(&((unsigned int *)vector->buf)[vector->index], s, \
		len * sizeof(unsigned int));
		vector->index = vector->index + len;
	}
	return (vector);
}
*/
