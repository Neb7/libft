/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:05:36 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 13:34:43 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Appends the string 'src' to the end of 'dest'. It will append at
 * 			most 'count - strlen(dest) - 1' characters. It will then
 * 			null-terminate the result if 'count' is not 0.
 * 
 * @param	dest The destination buffer
 * @param	src The source string
 * @param	count The size of the destination buffer
 * @return	The total length of the string it tried to create
 */
size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dest;

	if (!src)
		return (count);
	len_src = ft_strlen(src);
	if (!count || !dest)
		return (len_src + count);
	len_dest = ft_strlen(dest);
	if (len_dest >= count)
		return (len_src + count);
	i = len_dest;
	while (i < count - 1 && i - len_dest < len_src)
	{
		dest[i] = src[i - len_dest];
		i++;
	}
	dest[i] = 0;
	return (len_src + len_dest);
}
