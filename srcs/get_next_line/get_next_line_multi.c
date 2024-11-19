/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_multi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:47:27 by benpicar          #+#    #+#             */
/*   Updated: 2024/11/19 18:50:04 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_multi(int fd)
{
	static char	*buffer[1030];
	char		*d;
	ssize_t		l;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1029)
		return (NULL);
	d = NULL;
	if (gnl_strchar(buffer[fd], '\n') < 0)
	{
		buffer[fd] = gnl_suite(buffer[fd], fd, &l);
		if (l != BUFFER_SIZE && gnl_strchar(buffer[fd], '\n') < 0)
			d = gnl_substr(buffer[fd], 0, gnl_strlen(buffer[fd]));
	}
	if (! buffer[fd])
		return (NULL);
	if (! d && gnl_strchar(buffer[fd], '\n') != -1)
		d = gnl_substr(buffer[fd], 0, (gnl_strchar(buffer[fd], '\n') + 1));
	if (!d && gnl_strchar(buffer[fd], '\n') != -1)
		return (gnl_moinslbuffer(buffer[fd], gnl_strlen(buffer[fd])));
	if (d)
	{
		buffer[fd] = gnl_moinslbuffer(buffer[fd], gnl_strlen(d));
		return (d);
	}
	return (get_next_line(fd));
}
