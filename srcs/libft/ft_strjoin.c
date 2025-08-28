/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:57:19 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 13:37:27 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Joins two strings into a new string
 * 
 * @param	s1 The first string
 * @param	s2 The second string
 * @return	A pointer to the newly created string, or NULL on failure
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*d;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	d = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!d)
		return (NULL);
	ft_memcpy(d, s1, l1);
	ft_memcpy(d + l1, s2, l2 + 1);
	return (d);
}

/**
 * @brief	Joins two strings into a new string and frees the first string
 * 
 * @param	s1 The first string (will be freed)
 * @param	s2 The second string
 * @return	A pointer to the newly created string, or NULL on failure
 */
char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*d;

	if (!s1 || !s2)
		return (free(s1), NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	d = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!d)
		return (free(s1), NULL);
	ft_memcpy(d, s1, l1);
	ft_memcpy(d + l1, s2, l2 + 1);
	free(s1);
	return (d);
}
