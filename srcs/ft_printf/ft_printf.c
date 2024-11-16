/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:47:22 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/12 14:37:47 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_check_str(char *str, va_list lst, int ret, int j);
static int	ft_define_arg(va_list lst, char c, t_flags *flags);
static void	ft_check_flags(char *str, int *i, t_flags *flags);
static void	ft_init_flags(t_flags *flags);

/*Comme printf*/
int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	lst;

	if (!str)
		return (-1);
	va_start(lst, str);
	ret = ft_check_str((char *)str, lst, 0, 1);
	va_end(lst);
	return (ret);
}

/*Parsing de str*/
static int	ft_check_str(char *str, va_list lst, int ret, int j)
{
	int		i;
	t_flags	flags;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ret = ret + write(1, &str[i], 1);
		else
		{
			i++;
			if (!str[i])
				return (-1);
			else if (ft_test_char(&str[i], &j))
				ret = ret + write(1, &str[i - 1], j);
			else
			{
				ft_check_flags(str, &i, &flags);
				ret = ret + ft_define_arg(lst, str[i], &flags);
			}
		}
		i++;
	}
	return (ret);
}

/*Vérifie les flags*/
static void	ft_check_flags(char *str, int *i, t_flags *flags)
{
	ft_init_flags(flags);
	while (ft_strchar("# +-0", str[*i]) != -1)
	{
		if (str[*i] == '#')
			flags->dieze = true;
		else if (str[*i] == ' ')
			flags->space = true;
		else if (str[*i] == '+')
			flags->plus = true;
		else if (str[*i] == '-')
			flags->moins = true;
		else if (str[*i] == '0' )
			flags->zero = true;
		(*i)++;
	}
	if (str[*i] >= '1' && str[(*i)] <= '9')
		flags->min = ft_printf_atoi(str, i);
	if (str[*i] == '.')
	{
		(*i)++;
		flags->max = ft_printf_atoi(str, i);
	}
	ft_verif_flags(flags);
}

/*Arffiche les arguments selon le caractère de str donné*/
static int	ft_define_arg(va_list lst, char c, t_flags *flags)
{
	if (c == 'c')
		return (ft_printf_putchar(va_arg(lst, int), flags));
	else if (c == 's')
		return (ft_printf_putstr(va_arg(lst, char *), flags));
	else if (c == 'p')
		return (ft_printf_putptr(va_arg(lst, void *), flags));
	else if (c == 'd' || c == 'i')
		return (ft_putnbrstr(ft_itoa_base(va_arg(lst, int), \
		"0123456789x", flags), flags));
	else if (c == 'u')
		return (ft_putnbrstr(ft_itoa_base(va_arg(lst, unsigned int), \
		"0123456789x", flags), flags));
	else if (c == 'x')
		return (ft_putnbr_hex(ft_itoa_base(va_arg(lst, unsigned int), \
		"0123456789abcdefx", flags), flags));
	else if (c == 'X')
		return (ft_putnbr_hex(ft_itoa_base(va_arg(lst, unsigned int), \
		"0123456789ABCDEFX", flags), flags));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

/*Réinnitiale la structure t_flags*/
static void	ft_init_flags(t_flags *flags)
{
	flags->dieze = false;
	flags->moins = false;
	flags->plus = false;
	flags->space = false;
	flags->zero = false;
	flags->negatif = false;
	flags->max = -1;
	flags->min = -1;
	flags->s[0] = ' ';
	flags->s[1] = 0;
}
