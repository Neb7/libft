/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:20:10 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/13 13:18:53 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

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
