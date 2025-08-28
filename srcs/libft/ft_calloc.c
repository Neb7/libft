/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:20:10 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 16:07:48 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

/**
 * @brief	Allocates memory for an array of 'nmemb' elements of 'size' bytes
 * 			each and initializes all bytes to zero.
 * 
 * @param	nmemb The number of elements to allocate
 * @param	size The size of each element
 * @return	void* A pointer to the allocated memory, or NULL if an error occured
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;

	if (nmemb < 1 || size < 1)
	{
		r = (void *)malloc(0);
		if (!r)
			return (NULL);
		return (r);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	r = (void *)malloc(size * nmemb);
	if (!r)
		return (NULL);
	ft_bzero(r, size * nmemb);
	return (r);
}
