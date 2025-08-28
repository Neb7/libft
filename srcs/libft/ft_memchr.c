/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:53:20 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 14:58:58 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Searches for the first occurrence of the character 'c' in the
 * 
 * @param	s The memory area to search in
 * @param	c The character to search for
 * @param	n The number of bytes to search
 * @return	void* A pointer to the first occurrence of 'c' in 's',
 * 			or NULL if not found
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr = (const unsigned char *)s;

	i = 0;
	if (s != NULL)
	{
		while (i < n)
		{
			if (ptr[i] == (unsigned char)c)
				return ((void *)&ptr[i]);
			i++;
		}
	}
	return (NULL);
}

/**
 * @brief	Searches for the first occurrence of the character 'c' in the
 * 			memory area 's' within the first 'n' bytes.
 * 
 * @param	s The memory area to search in
 * @param	c The character to search for
 * @param	n The number of bytes to search
 * @return	ssize_t The index of the first occurrence of 'c' in 's',
 * 			or -1 if not found
 */
ssize_t	ft_memchar(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr = (const unsigned char *)s;

	i = 0;
	if (s != NULL)
	{
		while (i < n)
		{
			if (ptr[i] == (unsigned char)c)
				return (i);
			i++;
		}
	}
	return (-1);
}
