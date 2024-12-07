/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:33:32 by benpicar          #+#    #+#             */
/*   Updated: 2024/12/03 18:07:22 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_vector
{
	void	*buf;
	size_t	index;
	size_t	max_len;
}	t_vector;

typedef struct s_buffer
{
	t_vector		*vec;
	int				fd;
	struct s_buffer	*next;
	bool			end;
}	t_buffer;

/*Get_next_line*/

char		*get_next_line(int fd);

/*Get_next_line_utils*/

void		ft_free_all(t_buffer **start, t_buffer *tmp, t_buffer *tmp2, \
t_buffer *tmp3);

#endif