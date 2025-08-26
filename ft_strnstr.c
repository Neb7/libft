/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:22:32 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/22 11:34:22 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;
	size_t	j;

	len_little = 0;
	i = 0;
	while (little[len_little] != '\0')
		len_little++;
	if (len_little == 0)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && i + j < len && big[i + j] != '\0')
				j++;
			if (j == len_little)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
