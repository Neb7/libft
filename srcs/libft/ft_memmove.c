/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:02:24 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/29 12:02:03 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	i = n;
	if (dest > src && dest < src + n)
	{
		while (n % sizeof(long long) > 0)
		{
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
			n--;
			i--;
		}
		i = i / sizeof(long long);
		while (n > 0)
		{
			((long long *)dest)[i - 1] = ((long long *)src)[i - 1];
			i--;
			n = n - sizeof(long long);
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
