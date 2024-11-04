/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:29:40 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/28 15:06:41 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	found;

	if (s != NULL)
	{
		if (c == 0)
			return ((char *)&s[ft_strlen(s)]);
		i = 0;
		found = 0;
		while (s[i] != '\0')
		{
			if (s[i] == (char)c)
				found = i;
			i++;
		}
		if (found == 0 && s[0] == (char)c)
			return ((char *)s);
		else if (found > 0)
			return ((char *)&s[found]);
	}
	return (NULL);
}
