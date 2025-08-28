/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:39:48 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 16:17:05 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Searches for the first occurrence of the character 'c' in the
 * 			string 'str'.
 * 
 * @param	str The string to search in
 * @param	c The character to search for
 * @return	ssize_t The index of the first occurrence of 'c' in 'str',
 * 			or -1 if not found
 */
ssize_t	ft_strchar(char *str, int c)
{
	ssize_t	i;

	if (! str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	return (-1);
}
