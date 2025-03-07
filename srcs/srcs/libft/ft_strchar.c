/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:39:48 by benpicar          #+#    #+#             */
/*   Updated: 2024/12/03 12:11:20 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Search for 'c' in 'str' and return the first clue found or -1 if it does not
find nothing*/
ssize_t	ft_strchar(char *str, int c)
{
	ssize_t	i;

	if (! str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	return (-1);
}
