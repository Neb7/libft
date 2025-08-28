/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:23:22 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/28 16:06:37 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief	Checks if the character is a whitespace character
 * 
 * @param	c The character to check
 * @return	int 1 << 13 (8192) if the character is a whitespace character,
 * 			0 otherwise
 */
int	ft_isspace(int c)
{
	if ((char)c == ' ' || ((char)c < 13 && (char)c > 8))
		return (8192);
	return (0);
}
