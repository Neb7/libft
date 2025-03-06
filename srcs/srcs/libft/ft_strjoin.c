/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:57:19 by benpicar          #+#    #+#             */
/*   Updated: 2025/02/07 15:14:48 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*d;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	d = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!d)
		return (NULL);
	ft_memcpy(d, s1, l1);
	ft_memcpy(d + l1, s2, l2 + 1);
	return (d);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*d;

	if (!s1 || !s2)
		return (free(s1), NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	d = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!d)
		return (free(s1), NULL);
	ft_memcpy(d, s1, l1);
	ft_memcpy(d + l1, s2, l2 + 1);
	free(s1);
	return (d);
}
