/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:53:55 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/29 11:51:28 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Try to copy the 'size' - 1 character of 'src' into 'dest' by adding
a '\0' at the end
Returns the size of the string it has tried to create

WARNING Check not to set any NULL parameter!!!*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (size < 1)
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
