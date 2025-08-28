/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:14:58 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 16:10:52 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_null_string(void);

/**
 * @brief	Creates a substring from the string 's'
 * 
 * @param	s The string to create the substring from
 * @param	start The starting index of the substring in the string 's'
 * @param	len The maximum length of the substring
 * @return	char* The substring, or NULL if an error occured
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;
	size_t	len_s;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s <= start)
		return (ft_null_string());
	if (len_s - start >= len)
		d = (char *)malloc(sizeof(char) * (len + 1));
	else
		d = (char *)malloc(sizeof(char) * (len_s - start + 1));
	if (!d)
		return (NULL);
	while (start + i < len_s && i < len)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = 0;
	return (d);
}

/**
 * @brief	Returns an allocated empty string
 * 
 * @return	char* The allocated empty string, or NULL if an error occured
 */
static char	*ft_null_string(void)
{
	char	*d;

	d = (char *)malloc(sizeof(char) * 1);
	if (!d)
		return (NULL);
	d[0] = 0;
	return (d);
}
