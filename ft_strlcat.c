/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:05:36 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/22 11:27:22 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dest;

	len_src = 0;
	len_dest = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (!count)
		return (len_src);
	while (dest[len_dest] != '\0')
		len_dest++;
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
