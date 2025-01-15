/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:27:51 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/15 22:48:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd, char *buffer)
{
    int size_read;
    char    *tmp;
    char    *str;
    
    str = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (str == NULL)
        return (NULL);
    if (buffer == NULL)
        buffer = ft_strndup("");
    size_read = BUFFER_SIZE;
    while (ft_strchr(buffer, '\n') == 0 && size_read > 0)
    {
        size_read = read(fd, str, BUFFER_SIZE);
        if (size_read == -1)
            return(free(buffer), free(str), NULL);
        str[size_read + 1] = '\0';
        tmp = ft_strjoin(str, buffer);
        if (tmp == NULL)
            return (free(str), free(buffer), buffer = NULL, NULL);
        free(buffer);
    }
    buffer = tmp;
    free(str);
    return (buffer);
}

void    clear_buffer(char *buffer)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (buffer[i])
    {
        if (buffer[i] == '\n')
        {
            i++;
            break ;
        }
        i++;   
    }
    while (buffer[j])
    {
        buffer[j] = buffer[i + j];
        j++;
    }
    buffer[i + j] = '\0';
}

char    *get_next_line(int fd)
{
    static char *buffer = {0};
    char    *line;
    
    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = ft_read(fd, buffer);
    if (buffer == NULL)
        return (free(buffer), NULL);
    line = ft_strndup(buffer);
    clear_buffer(buffer);
    return (line);
}

int main()
{
    int fd;
    char *line;
    
    fd = open("text.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
}