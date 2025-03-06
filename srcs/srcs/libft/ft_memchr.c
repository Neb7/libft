/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:53:20 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/29 10:52:29 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr = (const unsigned char *)s;

	i = 0;
	if (s != NULL)
	{
		while (i < n)
		{
			if (ptr[i] == (unsigned char)c)
				return ((void *)&ptr[i]);
			i++;
		}
	}
	return (NULL);
}

ssize_t	ft_memchar(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr = (const unsigned char *)s;

	i = 0;
	if (s != NULL)
	{
		while (i < n)
		{
			if (ptr[i] == (unsigned char)c)
				return (i);
			i++;
		}
	}
	return (-1);
}
