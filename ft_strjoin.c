/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:57:19 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/22 11:24:17 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*d;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	d = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		d[i] = s1[i];
		i++;
	}
	while (i < l1 + l2)
	{
		d[i] = s2[i - l1];
		i++;
	}
	d[i] = 0;
	return (d);
}
