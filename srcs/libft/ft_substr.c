/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:14:58 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/29 10:57:21 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_test(void);

/*Create a sub-string of 's' with malloc from 'start' and maximum size 'len'*/
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
		return (ft_test());
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

static char	*ft_test(void)
{
	char	*d;

	d = (char *)malloc(sizeof(char) * 1);
	if (!d)
		return (NULL);
	d[0] = 0;
	return (d);
}
