/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:53:55 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/28 15:06:17 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (!src)
		return (0);
	len = ft_strlen(src);
	if (!dest || size < 1)
		return (len);
	i = 0;
	while (i < size - 1 && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}
