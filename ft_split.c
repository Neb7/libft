/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:57:42 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/22 11:24:58 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_fail_alloc(char **d, int i);
static char	*ft_strdup_tmp3(char const *s, size_t *j, int n, char c);
static int	ft_nbrstr(char const *str, char c);
static char	**ft_is_not_nul(char const *s, char c, int nb_s, int i);

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

static char	*ft_strdup_tmp3(char const *s, size_t *j, int n, char c)
{
	char	*dp;
	int		i;

	i = 0;
	while (s[n] != '\0' && s[n] != c)
		n++;
	dp = (char *) malloc(sizeof(char) * (n + 1));
	if (! dp)
		return (NULL);
	while (i < n)
	{
		dp[i] = s[i];
		i++;
	}
	dp[i] = 0;
	*j = *j + n;
	return (dp);
}

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
