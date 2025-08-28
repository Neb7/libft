/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:41:59 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 11:54:14 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Compares the first 'n' characters of 's1' with 's2' and returns the
 * 			difference of the first different character
 * 
 * @param	s1 The first string to compare
 * @param	s2 The second string to compare
 * @param	n The number of characters to compare
 * @return	int The difference between the first different character of 's1'
 * 			and 's2', or 0 if they are equal
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * @brief	Compares two strings lexicographically
 * 
 * @param	s1 The first string to compare
 * @param	s2 The second string to compare
 * @return	int The difference between the first different character of 's1'
 * 			and 's2', or 0 if they are equal
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
