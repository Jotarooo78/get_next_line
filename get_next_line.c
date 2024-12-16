/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:50:20 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/16 15:47:29 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    int size_read;
    char    *str;
    char *line;
    char static buf[BUFFER_SIZE + 1];

    // if (fd == 0)
    //     return (NULL);
    str = ft_strjoin(str, buf);
    while (size_read == BUFFER_SIZE || !ft_strchr(buf, '\n'))
    {
        size_read = read(fd, buf, BUFFER_SIZE);
        if (size_read == -1)
            return (NULL);
        str = ft_strjoin(str, buf);
    }
    line = ft_strndup(str, '\n');
    ft_clean_str(buf);
    return (line);
}

char    *ft_clean_str(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if(str[i]== '\n')
        {
            i++;
            break;
        }
        i++;
    }
    while (str[i])
    {
        str[j] = str[i];
        j++;
        i++;
    }
    return (str);
}
