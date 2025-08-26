/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:38:18 by benpicar          #+#    #+#             */
/*   Updated: 2025/02/05 21:25:34 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	d = (char *)malloc(sizeof(char) * len);
	if (!d)
		return (NULL);
	ft_memcpy(d, s, len);
	return (d);
}
