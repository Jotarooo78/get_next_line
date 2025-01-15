/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:27:51 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/15 16:59:03 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_read(int fd, char *buffer)
{
    int size_read;
    
    size_read = read(fd, buffer, BUFFER_SIZE);
    if (size_read == -1)
        return(buffer[0] = '\0', free(buffer), NULL);
    
}

void    clear_buffer(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] && ft_strchr(str[i], '\n') == 0)
        i++;
    while (str[j])
    {
        str[j] = str[i + j];
        j++;
    }
}

char    *get_next_line(int fd)
{
    static char *buffer = {0};
    char    *line;
    int     size_read;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    size_read = BUFFER_SIZE;
    line = ft_strdup(buffer);
    while (size_read == BUFFER_SIZE)
}