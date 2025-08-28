/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:57:42 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 14:48:50 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_fail_alloc(char **d, int i);
static char	*ft_strdup_tmp3(char const *s, size_t *j, int n, char c);
static int	ft_nbrstr(char const *str, char c);
static char	**ft_is_not_nul(char const *s, char c, int nb_s, int i);

/**
 * @brief	Splits a string into an array of strings using a delimiter
 * 
 * @param	s The string to split
 * @param	c The delimiter character
 * @return	char** The array of strings, or NULL if an error occured
 */
char	**ft_split(char const *s, char c)
{
	char	**d;

	if (! s)
	{
		d = (char **)malloc(sizeof(char *) * 1);
		if (! d)
			return (NULL);
		d[0] = NULL;
		return (d);
	}
	return (ft_is_not_nul(s, c, ft_nbrstr(s, c), 0));
}

/**
 * @brief	Counts the number of substrings in a string separated by a delimiter
 * 
 * @param	str The string to analyze
 * @param	c The delimiter character
 * @return	int The number of substrings
 */
static char	**ft_is_not_nul(char const *s, char c, int nb_s, int i)
{
	char	**d;
	size_t	j;

	d = (char **) malloc(sizeof(char *) * (nb_s + 1));
	if (! d)
		return (NULL);
	j = 0;
	while (c == s[j])
		j++;
	while (i < nb_s)
	{
		d[i] = ft_strdup_tmp3(&s[j], &j, 0, c);
		if (! d[i])
			return (ft_fail_alloc(d, i));
		while (s[j] != '\0' && c == s[j])
			j++;
		i++;
	}
	d[i] = NULL;
	return (d);
}

/**
 * @brief	Frees the allocated memory for the array of strings in case of
 * 			failure
 * 
 * @param	d The array of strings to free
 * @param	i The number of strings allocated
 * @return	NULL Always returns NULL
 */
static char	**ft_fail_alloc(char **d, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(d[j]);
		j++;
	}
	free(d);
	return (NULL);
}

/**
 * @brief	Duplicates a substring from the string 's' until the delimiter 'c'
 * 
 * @param	s The string to duplicate from
 * @param	j A pointer to the current index in the string 's'
 * @param	n The starting index for duplication
 * @param	c The delimiter character
 * @return	char* The duplicated substring, or NULL if an error occured
 */
static char	*ft_strdup_tmp3(char const *s, size_t *j, int n, char c)
{
	char	*dp;

	while (s[n] != '\0' && s[n] != c)
		n++;
	dp = (char *) malloc(sizeof(char) * (n + 1));
	if (! dp)
		return (NULL);
	ft_memcpy(dp, s, n);
	dp[n] = 0;
	*j = *j + n;
	return (dp);
}

/**
 * @brief	Counts the number of substrings in a string separated by a delimiter
 * 
 * @param	str The string to analyze
 * @param	c The delimiter character
 * @return	int The number of substrings
 */
static int	ft_nbrstr(char const *str, char c)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (str[i])
	{
		if (c != str[i])
		{
			if (!in_word)
				count++;
			in_word = 1;
		}
		else
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}
