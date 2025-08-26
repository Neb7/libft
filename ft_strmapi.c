/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:38:12 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/22 11:05:43 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static char	*ft_s_empty(void);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	d = (char *)malloc(sizeof(char) * (i + 1));
	if (! d)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = (*f)(i, s[i]);
		i++;
	}
	d[i] = 0;
	return (d);
}
