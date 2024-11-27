/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:52:35 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/26 15:07:54 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_putnil(char *str, t_flags *flags, int len);
static int	ft_putnull(char *str, t_flags *flags, int len);

/*Putchar avec les flags*/
int	ft_printf_putchar(int c, t_flags *flags)
{
	int	i;

	i = 0;
	if (!flags->moins)
		while (++i < flags->min)
			write(flags->fd, " ", 1);
	write(flags->fd, &c, 1);
	if (flags->moins)
		while (++i < flags->min)
			write(flags->fd, " ", 1);
	return (i);
}

/*Putstr avec les flags*/
int	ft_printf_putstr(char *str, t_flags *flags)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	if (!str)
		return (ft_putnull("(null)", flags, 6));
	i = ft_strlen(str);
	if (flags->max != -1 && flags->max < i)
		i = flags->max;
	if (flags->moins)
		write(flags->fd, str, i);
	if (flags->min != -1 && flags->min > i)
	{
		j = i - 1;
		while (++j < flags->min)
			ret = ret + write(flags->fd, flags->s, 1);
	}
	if (!flags->moins)
		write(flags->fd, str, i);
	ret = ret + i;
	return (ret);
}

/*Affiche l'adresse du pointer 'ptr' en hexadecimal en appliquant les flags*/
int	ft_printf_putptr(void *ptr, t_flags *flags)
{
	unsigned long int	a;
	char				buf[20];
	int					len;

	if (!ptr)
		return (ft_putnil(PTRNULL, flags, ft_strlen(PTRNULL)));
	a = (unsigned long int)ptr;
	len = ft_len_a(a, 0, 16) + 2;
	buf[0] = '0';
	buf[1] = 'x';
	buf[len] = 0;
	while (a > 0)
	{
		buf[len - 1] = "0123456789abcdef"[a % 16];
		a = a / 16;
		len--;
	}
	if (flags->zero)
		flags->s[0] = '0';
	return (ft_printf_putstr(buf, flags));
}

static int	ft_putnil(char *str, t_flags *flags, int len)
{
	int	j;
	int	ret;

	j = -1;
	ret = len;
	if (flags->moins)
		write(flags->fd, str, len);
	if (flags->min != -1 && flags->min > len)
		while (++j < flags->min - len)
			ret = ret + write(flags->fd, flags->s, 1);
	if (!flags->moins)
		write(flags->fd, str, len);
	return (ret);
}

static int	ft_putnull(char *str, t_flags *flags, int len)
{
	int	j;
	int	ret;

	j = -1;
	ret = len;
	if (flags->moins && (flags->max >= len || flags->max == -1))
		write(flags->fd, str, len);
	if (flags->min != -1 && flags->min > len && flags->max >= len)
		while (++j < flags->min - len)
			ret = ret + write(flags->fd, flags->s, 1);
	else if (flags->max != -1 && flags->max < len && flags->min != -1)
		while (++j < flags->min)
			ret = ret + write(flags->fd, flags->s, 1);
	if (!flags->moins && (flags-> max >= len || flags->max == -1))
		write(flags->fd, str, len);
	if (!(flags-> max >= len) && flags->max != -1)
		ret = ret - len;
	return (ret);
}
