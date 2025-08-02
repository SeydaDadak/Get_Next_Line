/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 09:24:01 by sdadak            #+#    #+#             */
/*   Updated: 2025/08/02 13:50:09 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	read_to_stash(char **stash, int fd)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (!ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && *stash[0] == '\0'))
			return (free(*stash), free(buffer), *stash = NULL, 0);
		if (bytes_read == 0)
			return (free(buffer), 1);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*stash, buffer);
		if (!temp)
			return (free(*stash), free(buffer), *stash = NULL, 0);
		free(*stash);
		*stash = temp;
	}
	return (free(buffer), 2);
}

static char	*ft_line(char **stash)
{
	char	*line;
	char	*new_stash;
	int		i;

	i = 0;
	while ((*stash)[i] != '\n')
		i++;
	line = ft_substr(*stash, 0, i + 1);
	if (!line)
		return (free(*stash), *stash = NULL, NULL);
	new_stash = ft_substr(*stash, i + 1, ft_strlen(*stash) - i - 1);
	free(*stash);
	if (!new_stash)
		return (free(line), *stash = NULL, NULL);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	int			ctrl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	if (!stash[fd])
		return (NULL);
	ctrl = read_to_stash(&stash[fd], fd);
	if (ctrl == 0)
		return (NULL);
	else if (ctrl == 1)
		return (line = stash[fd], stash[fd] = NULL, line);
	return (ft_line(&stash[fd]));
}
