/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:25:19 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 14:43:34 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Searches for the first occurrence of the character 'c' in the
 * 
 * @param	s The string to search in
 * @param	c The character to search for
 * @return	char* A pointer to the first occurrence of 'c' in 's',
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == (char)c)
				return ((char *)&s[i]);
			i++;
		}
		if ((char)c == '\0')
			return ((char *)&s[i]);
	}
	return (NULL);
}
