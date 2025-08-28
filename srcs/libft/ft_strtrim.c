/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:26:06 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 11:48:47 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Trims the string 's1' with the characters of the string 'set'
 * 
 * @param	s1 The string to trim
 * @param	set The set of characters to trim from the string
 * @return	char* The trimmed string, or NULL if an error occured
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*d;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	while (ft_strchar((char *)set, s1[i]) != -1 && s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
		return (NULL);
	while (s1[j] != '\0')
		j++;
	j--;
	while (ft_strchar((char *)set, s1[j]) != -1)
		j--;
	d = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!d)
		return (NULL);
	ft_memcpy(d, s1, j - i + 1);
	d[j - i + 1] = 0;
	return (d);
}
