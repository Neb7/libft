/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:22:32 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 11:53:07 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Locates the first occurrence of the null-terminated string 'little'
 *          in the string 'big' within the first 'len' characters.
 * 
 * @param	big The string to search in
 * @param	little The string to search for
 * @param	len The maximum length to search
 * @return	char* A pointer to the first occurrence of 'little' in 'big',
 * 			or NULL if not found
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;
	size_t	j;

	len_little = ft_strlen(little);
	i = 0;
	if (len_little == 0)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && i + j < len && big[i + j] != '\0')
				j++;
			if (j == len_little)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
