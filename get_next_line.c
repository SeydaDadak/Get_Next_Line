#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char *ft_get_next_line(int fd)
{
    static char     *stash;
    char    buffer[BUFFER_SIZE + 1]; 
    int     bytes_read;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    if(!stash)
    {
        stash = malloc(1);
        if (!stash)
            return (NULL);
        stash[0] = '\0';
    }
    
    while (!ft_strchr(stash, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if(bytes_read == -1) // birkaç durum var bak bunlara
        {
            free(stash);
            stash = NULL; //dangling pointer
            return (NULL);
        }
        if(bytes_read == 0) // ? seyda için 
        {
            return (NULL);
        }
        buffer[bytes_read] = '\0';

        stash = ft_strjoin(stash, buffer);
        if(!stash)
            return (NULL);
    }
    int i = 0;
    char *temp;
    while (stash[i])
    {
        if (stash[i] == '\n')
        {
            temp = ft_substr(stash, 0, i + 1);
            if (stash[i + 1] != '\0' || 0 != bytes_read)
            {
                //free(stash);
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
    int fd = open("asd.txt", O_CREAT | O_RDWR , 0777);
    printf("%s", ft_get_next_line(fd));
    printf("%s", ft_get_next_line(fd));
    printf("%s", ft_get_next_line(fd));
    printf("%s", ft_get_next_line(fd));
    printf("%s", ft_get_next_line(fd));
    printf("%s", ft_get_next_line(fd));
    printf("%s", ft_get_next_line(fd));
    printf("%s", ft_get_next_line(fd));
    printf("%s", ft_get_next_line(fd));
    printf("%s", ft_get_next_line(fd));
    printf("%s", ft_get_next_line(fd));
}


