/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:34:42 by benpicar          #+#    #+#             */
/*   Updated: 2024/12/09 12:31:43 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_valabs(int val)
{
	if (val < 0)
		return (-val);
	else
		return (val);
}
