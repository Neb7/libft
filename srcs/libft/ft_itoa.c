/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:18:07 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 16:01:41 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_n_negatif(unsigned int nb, char *d, int i);
static void	ft_n_positif(unsigned int nb, char *d, int i);
static int	ft_len_d(int n, int count, unsigned int n_un);

/**
 * @brief	Converts an integer to a allocated null-terminated string
 * 
 * @param	n The integer to convert
 * @return	char* The converted string, or NULL if an error occured
 */
char	*ft_itoa(int n)
{
	char	*d;
	int		len_d;

	len_d = ft_len_d(n, 0, 0);
	d = (char *)malloc(sizeof(char) * len_d);
	if (! d)
		return (NULL);
	if (n == 0)
	{
		d[0] = '0';
		d[1] = 0;
	}
	else if (n < 0)
		ft_n_negatif(-n, d, len_d - 1);
	else
		ft_n_positif(n, d, len_d - 1);
	return (d);
}

static void	ft_n_negatif(unsigned int nb, char *d, int i)
{
	d[i] = 0;
	i--;
	while (nb != 0)
	{
		d[i] = "0123456789"[nb % 10];
		i--;
		nb = nb / 10;
	}
	d[i] = '-';
}

static void	ft_n_positif(unsigned int nb, char *d, int i)
{
	d[i] = 0;
	i--;
	while (nb != 0)
	{
		d[i] = "0123456789"[nb % 10];
		i--;
		nb = nb / 10;
	}
}

static int	ft_len_d(int n, int count, unsigned int n_un)
{
	if (n <= 0)
	{
		count++;
		n_un = -n;
	}
	else
		n_un = n;
	while (n_un != 0)
	{
		count++;
		n_un = n_un / 10;
	}
	count++;
	return (count);
}
