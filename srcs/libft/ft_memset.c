/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:38:43 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 14:52:50 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Fills the first 'n' bytes of the memory area pointed to by 's'
 * 			with the constant byte 'c'
 * 
 * @param	s The memory area to fill
 * @param	c The byte to fill the memory area with
 * @param	n The number of bytes to fill
 * @return	The memory area 's'
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	long long	c8;

	i = -1;
	c8 = 0;
	while (++i < sizeof(long long))
		c8 = c8 | (long long)(unsigned char)c << 8 * i;
	i = 0;
	while (n > sizeof(long long))
	{
		((long long *)s)[i] = c8;
		i++;
		n = n - sizeof(long long);
	}
	i = i * sizeof(long long);
	while (n > 0)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (s);
}
