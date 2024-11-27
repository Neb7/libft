/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:52:11 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/27 11:02:43 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (n >= sizeof(long long))
		{
			((long long *)s)[i] = 0;
			i++;
			n = n - sizeof(long long);
		}
		i = i * sizeof(long long);
		while (n > 0)
		{
			((unsigned char *)s)[i] = 0;
			n--;
			i++;
		}
	}
}
