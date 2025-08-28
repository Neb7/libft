/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:38:18 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 13:38:39 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Duplicates a string
 * 
 * @param	s The string to duplicate
 * @return	A pointer to the duplicated string, or NULL on failure
 */
char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	d = (char *)malloc(sizeof(char) * len);
	if (!d)
		return (NULL);
	ft_memcpy(d, s, len);
	return (d);
}
