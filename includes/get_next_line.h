/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:33:32 by benpicar          #+#    #+#             */
/*   Updated: 2025/01/07 15:50:16 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef S_VECTOR
#  define S_VECTOR

typedef struct s_vector
{
	void	*buf;
	size_t	index;
	size_t	max_len;
}	t_vector;

# endif

typedef struct s_buffer
{
	t_vector		*vec;
	int				fd;
	struct s_buffer	*next;
	bool			end;
}	t_buffer;

/*Get_next_line*/

char		*get_next_line(int fd, int end);

/*Get_next_line_utils*/

void		ft_free_all(t_buffer **start, t_buffer *tmp, t_buffer *tmp2, \
t_buffer *tmp3);

#endif