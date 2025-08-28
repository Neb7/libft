/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:29:40 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 11:49:40 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Searches for the last occurrence of the character 'c' in the
 * 			string 's'
 * 
 * @param	s The string to search in
 * @param	c The character to search for
 * @return	char* A pointer to the last occurrence of 'c' in 's',
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	found;

	if (s != NULL)
	{
		if (c == 0)
			return ((char *)&s[ft_strlen(s)]);
		i = 0;
		found = 0;
		while (s[i] != '\0')
		{
			if (s[i] == (char)c)
				found = i;
			i++;
		}
		if (found == 0 && s[0] == (char)c)
			return ((char *)s);
		else if (found > 0)
			return ((char *)&s[found]);
	}
	return (NULL);
}
