/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:38:43 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/28 15:05:34 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (i < n)
		{
			((unsigned char *)s)[i] = (unsigned char)c;
			i++;
		}
		return (s);
	}
	return (NULL);
}
