/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:52:34 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/13 13:47:54 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*Longueur necessaire pour mettre 'a' dans un 'char *'*/
int	ft_len_a(unsigned long int a, int len, unsigned int len_base)
{
	while (a > 0)
	{
		a = a / len_base;
		len++;
	}
	return (len);
}

/*Atoi simplifié*/
ssize_t	ft_printf_atoi(char *str, int *i)
{
	ssize_t	y;

	y = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		y = (y * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (y);
}

/*Met à jour flags par rapport aux flags qui l'emporte sur d'autres*/
void	ft_verif_flags(t_flags *flags)
{
	if (flags->plus)
		flags->space = false;
	if (flags->moins || flags->max != -1)
		flags->zero = false;
}

void	ft_put_flags_negatif(t_flags *flags)
{
	flags->negatif = true;
	flags->plus = false;
	flags->space = false;
}

int	ft_test_char(char *str, int *j)
{
	int	i;

	i = 0;
	while (ft_strchar("0 -+#", str[i]) != -1)
		i++;
	while (ft_strchar("0123456789.", str[i]) != -1)
		i++;
	if (ft_strchar("cspdiuxX%", str[i]) < 0)
	{
		*j = i + 1;
		return (-1);
	}
	return (0);
}
