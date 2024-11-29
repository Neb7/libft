/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:26:06 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/29 10:57:50 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strim_tmp(char const *s1, char const *set, int i, int j);
static int	ft_strchar_tmp(char const *str, char to_find);

/*Trime the string 's1' with the characters of the string 'set'*/
char	*ft_strtrim(char const *s1, char const *set)
{
	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	else
		return (ft_strim_tmp(s1, set, 0, 0));
}

static char	*ft_strim_tmp(char const *s1, char const *set, int i, int j)
{
	char	*d;
	int		index_d;

	while (ft_strchar_tmp(set, s1[i]) != -1 && s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	while (s1[j] != '\0')
		j++;
	j--;
	while (ft_strchar_tmp(set, s1[j]) != -1)
		j--;
	d = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!d)
		return (NULL);
	index_d = -1;
	while (++index_d <= j - i)
		d[index_d] = s1[i + index_d];
	d[index_d] = 0;
	return (d);
}

static int	ft_strchar_tmp(char const *str, char to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}
