/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:34:40 by sdadak            #+#    #+#             */
/*   Updated: 2025/07/30 21:14:01 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char *ft_get_next_line(int fd)
{
    static char     *stash;
    char    buffer[BUFFER_SIZE + 1]; 
    int     bytes_read = 1;
    int i = 0;
    char *temp;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    if(!stash)
    {
        stash = malloc(1);
        if (!stash)
        {
            return (NULL);
        }
        stash[0] = '\0';
    }
    while (!ft_strchr(stash, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if(bytes_read == -1)
        {
            free(stash);
            stash = NULL;
            return (NULL);
        }
        if(bytes_read == 0) 
        {
		    if (stash[0] == '\0')
            {
                free(stash);
                stash = NULL;
			    return (NULL);
            }
            return (stash);
        }
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(stash, buffer);
        if(!temp)
        {
            free(stash);
            return (NULL);
        }
        free(stash);
        stash = temp;
    }
    while (stash[i])
    {
        if (stash[i] == '\n')
        {
            temp = ft_substr(stash, 0, i + 1);
            if (stash[i + 1] != '\0' || bytes_read != 0)
            {
                stash = ft_substr(stash, i + 1, ft_strlen(stash) - i + 1);
            }
            return (temp);
        }
        i++;
    }
    return (stash);
}

int main()
{
	int fd = open("asd.txt", O_RDWR , 0777);

    	printf("%s", ft_get_next_line(fd));
    	printf("%s", ft_get_next_line(fd));
    	printf("%s", ft_get_next_line(fd));
        
        close(fd);
}
