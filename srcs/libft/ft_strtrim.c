/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:26:06 by benpicar          #+#    #+#             */
/*   Updated: 2024/12/03 12:10:49 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Trime the string 's1' with the characters of the string 'set' and free s1

WARNING s1 MUST BE malloc*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*d;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	while (ft_strchar((char *)set, s1[i]) != -1 && s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
		return (NULL);
	while (s1[j] != '\0')
		j++;
	j--;
	while (ft_strchar((char *)set, s1[j]) != -1)
		j--;
	d = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!d)
		return (NULL);
	ft_memcpy(d, s1, j - i + 1);
	d[j - i + 1] = 0;
	return (d);
}
