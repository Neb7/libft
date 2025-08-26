/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:20:10 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/18 12:54:30 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;
	size_t	i;

	if (nmemb < 1 || size < 1)
	{
		r = (void *)malloc(0);
		if (!r)
			return (NULL);
		return (r);
	}
	if (size * nmemb / nmemb != size)
		return (NULL);
	r = (void *)malloc(size * nmemb);
	if (!r)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)r)[i] = 0;
		i++;
	}
	return (r);
}
