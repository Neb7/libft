/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:02:24 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/17 11:19:08 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (d > s && d < s + n)
		while (n--)
			d[n] = s[n];
	else
		while (i++ < n)
			d[i - 1] = s[i - 1];
	return (dest);
}
