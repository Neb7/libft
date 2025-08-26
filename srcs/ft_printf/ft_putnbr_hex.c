/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:55:05 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/26 15:08:33 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_write_str_hex(char *str, int len_str, t_flags *flags);

/*Affiche le nombre 'str' (qui est en base 16) placer en paramètre en fonction
des flags*/
int	ft_putnbr_hex(char *str, t_flags *flags)
{
	int	len_str;
	int	j;
	int	ret;

	ret = 0;
	if (flags->zero)
		flags->s[0] = '0';
	len_str = ft_strlen(str);
	if (flags->dieze && flags->zero && len_str > 2)
		write(flags->fd, str, 2);
	if (flags->moins)
		ret = ret + ft_write_str_hex(str, len_str, flags);
	if (flags->min != -1 && (flags->min > len_str || flags->min > flags->max))
	{
		if (flags->max + (flags->dieze * 2) > len_str)
			j = flags->max - 1 + (flags->dieze * 2);
		else
			j = len_str - 1;
		while (++j < flags->min)
			ret = ret + write(flags->fd, flags->s, 1);
	}
	if (!flags->moins)
		ret = ret + ft_write_str_hex(str, len_str, flags);
	free(str);
	return (ret);
}

static int	ft_write_str_hex(char *str, int len_str, t_flags *flags)
{
	int	j;
	int	ret;
	int	have_dieze;

	have_dieze = 0;
	if (flags->dieze && len_str > 2)
		have_dieze = 2;
	if (flags->dieze && !flags->zero && len_str > 2)
		write(flags->fd, str, 2);
	ret = 0;
	j = -1;
	if (flags->max != -1 && flags->max > len_str - have_dieze)
		while (++j < flags->max - len_str + have_dieze)
			ret = ret + write(flags->fd, "0", 1);
	write(flags->fd, &str[have_dieze], len_str - have_dieze);
	ret = ret + len_str;
	return (ret);
}
