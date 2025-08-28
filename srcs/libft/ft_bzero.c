/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:52:11 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 16:08:35 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Sets the first 'n' bytes of the memory area pointed to by 's' to
 * 			zero (bytes containing '\0').
 * 
 * @param	s The memory area to set to zero
 * @param	n The number of bytes to set to zero
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (n >= sizeof(long long))
		{
			((long long *)s)[i] = 0;
			i++;
			n = n - sizeof(long long);
		}
		i = i * sizeof(long long);
		while (n > 0)
		{
			((unsigned char *)s)[i] = 0;
			n--;
			i++;
		}
	}
}
