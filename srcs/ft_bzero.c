/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:52:11 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/27 12:11:35 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s != NULL)
	{
		while (i * 8 < n && n / 8)
		{
			((long *)s)[i] = 0;
			i++;
			j = j + 8;
		}
		while (j % 8 < n % 8)
		{
			((unsigned char *)s)[j] = 0;
			j++;
		}
	}
}