/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:39:31 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 16:09:48 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Converts a string to an integer
 * 
 * @param	nptr The string to convert
 * @return	int The converted integer
 */
int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	res;

	s = 1;
	i = 0;
	res = 0;
	if (!nptr)
		return (0);
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s = -s;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * s);
}

/**
 * @brief	Converts a string to an integer and updates the index
 * 
 * @param	nptr The string to convert
 * @param	idx A pointer to the index to update
 * @return	int The converted integer
 */
int	ft_atoi_i(const char *nptr, int *idx)
{
	int	i;
	int	s;
	int	res;

	s = 1;
	i = 0;
	res = 0;
	if (!nptr)
		return (0);
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s = -s;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	*idx = *idx + i;
	return (res * s);
}
