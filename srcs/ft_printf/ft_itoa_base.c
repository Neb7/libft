/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:51:27 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/13 13:47:39 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_plus_space(char *d, t_flags *flags, int len_d);
static void	ft_add_flags(char *d, t_flags *flags, char *base, long int n);
static char	*ft_n_positif(long int n, char *base, int i, \
unsigned int len_base);
static int	ft_len_d(long int n, t_flags *flags, unsigned int len_base);

/*Transforme un long int en un char * en une base donné*/
char	*ft_itoa_base(long int n, char *base, t_flags *flags)
{
	char	*d;
	int		len_d;
	int		len_base;

	len_base = ft_strlen(base) - 1;
	len_d = ft_len_d(n, flags, len_base);
	if (n == 0)
	{
		if ((flags->plus || flags->space) && flags->max == -1)
			len_d++;
		if (flags->max != -1 && !flags->plus && !flags->space)
			return ((char *)ft_calloc(1, sizeof(char)));
		d = (char *)malloc(sizeof(char) * len_d);
		if (!d)
			return (NULL);
		ft_plus_space(d, flags, len_d);
	}
	else
	{
		d = ft_n_positif(n, base, len_d - 1, len_base);
		ft_add_flags(d, flags, base, n);
	}
	if (n < 0)
		ft_put_flags_negatif(flags);
	return (d);
}

static void	ft_plus_space(char *d, t_flags *flags, int len_d)
{
	if (flags->plus && flags->max == -1)
		d[len_d - 3] = '+';
	else if (flags->space && flags->max == -1)
		d[len_d - 3] = ' ';
	if (flags->plus && flags->max != -1)
		d[len_d - 2] = '+';
	else if (flags->space && flags->max != -1)
		d[len_d - 2] = ' ';
	else
		d[len_d - 2] = '0';
	d[len_d - 1] = 0;
}

static void	ft_add_flags(char *d, t_flags *flags, char *base, long int n)
{
	int	len_base;

	len_base = ft_strlen(base) - 1;
	if (len_base == 16 && flags->dieze)
	{
		d[0] = '0';
		d[1] = base[16];
	}
	else if (len_base == 10 && (flags->plus || flags->space) && n >= 0)
	{
		if (flags->plus)
			d[0] = '+';
		else
			d[0] = ' ';
	}
}

static char	*ft_n_positif(long int n, char *base, int i, \
unsigned int len_base)
{
	char				*d;
	unsigned long int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	d = (char *)malloc(sizeof(char) * (i + 1));
	if (!d)
		return (NULL);
	d[i] = 0;
	i--;
	while (nb != 0)
	{
		d[i] = base[nb % len_base];
		i--;
		nb = nb / len_base;
	}
	if (n < 0)
		d[i] = '-';
	return (d);
}

static int	ft_len_d(long int n, t_flags *flags, unsigned int len_base)
{
	int				count;
	unsigned int	n_un;

	count = 0;
	n_un = 0;
	if (n <= 0)
	{
		count++;
		n_un = -n;
	}
	else
	{
		if (len_base == 10 && (flags->plus || flags->space))
			count++;
		n_un = n;
	}
	while (n_un != 0)
	{
		count++;
		n_un = n_un / len_base;
	}
	count++;
	if (len_base == 16 && flags->dieze && n)
		count = count + 2;
	return (count);
}
