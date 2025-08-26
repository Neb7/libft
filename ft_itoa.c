/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:18:07 by benpicar          #+#    #+#             */
/*   Updated: 2024/10/18 12:54:07 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_n_negatif(unsigned int nb, char *d, int i);
static void	ft_n_positif(unsigned int nb, char *d, int i);
static int	ft_len_d(int n, int count, unsigned int n_un);

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
		d[i] = (nb % 10) + '0';
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
		d[i] = (nb % 10) + '0';
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
