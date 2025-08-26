/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:57:38 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/15 14:27:56 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest != NULL && src != NULL)
	{
		while (n >= sizeof(long long))
		{
			((long long *)dest)[i] = ((long long *)src)[i];
			i++;
			n = n - sizeof(long long);
		}
		i = i * sizeof(long long);
		while (n > 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			n--;
			i++;
		}
	}
	return (dest);
}
