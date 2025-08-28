/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:34:42 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 11:44:29 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief	Returns the absolute value of an integer
 * 
 * @param	val The integer to get the absolute value of
 * @return	int The absolute value of the integer
 */
int	ft_valabs(int val)
{
	if (val < 0)
		return (-val);
	else
		return (val);
}
