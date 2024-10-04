#include <unistd.h>
#include <stdlib.h>

char *ft_strdup(char *str)
{
    int len = 0;
    int i = 0;
    char *src;

    while(str[len])
        len++;
    src = malloc(sizeof(char ) * len + 1);
    if(!src)
        return(NULL);
    while(str[i])
    {
        src[i] = str[i];
        i++;
    }
    src[i] = '\0';
    return(src);
}

char *get_next_line(int fd)
{
    int index = 0;
    int b;
    char line[7999999] = {0};
    char buffer;

    if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    b = read(fd, &buffer, 1);
    while(b > 0)
    {
        line[i++] = buffer;
        if(buffer == '\n')
            break;
        b = read(fd, &buffer, 1);
    }
    if(!line[0])
        return(NULL);
    return(ft_strdup(line));
}


// easy way
#include "get_next_line.h"
char	*get_next_line(int fd)
{
    int i = 0;
    int store_read;
    char	line;
    char	*buffer;

    if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
	return (NULL);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
 	return (NULL);
    store_read = read(fd, &line, 1);
    while (store_read > 0)
    {
	buffer[index++] = line;
	if (line == '\n')
		break ;
	store_read = read(fd, &line, 1);
    }
    buffer[index] = '\0';
    if (index == 0 && store_read <= 0)
	return (free(buffer), (NULL));
    return (buffer);
}
