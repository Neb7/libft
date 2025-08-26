/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:39:48 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/15 16:02:37 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Cherche 'c' dans 'str' et renvoie le premier indice trouvé ou -1 sùil ne
trouve rien*/
int	ft_strchar(char *str, int c)
{
	int	i;

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
