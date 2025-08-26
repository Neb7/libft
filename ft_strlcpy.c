/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:53:55 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/15 12:41:00 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	if (size < 1)
		return (len);
	while (i < size - 1 && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}
