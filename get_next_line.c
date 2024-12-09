/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:50:47 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/09 15:41:06 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    int i;
    int j;
    char static   *stash;
    char    *buf;
    char    *line;
    
    i = 0;
    j = 0;
    fd = open(buf, O_RDONLY);
    if (fd == NULL)
        return (NULL);
    while (buf[i])
    {
        ft_strjoin(read(fd, buf, BUFFER_SIZE), &stash[j]);
        j += 5;
        check_return(stash, line);
    }  
    return (0);
}

char    clean_stash(char *stash)
{
       
}

char    clean_line(char *line)
{
    
}

size_t  check_return(char *stash, char *line)
{
    int i;

    i = 0;
    while (stash[i])
    {
        if (stash[i] == '\n')
        {
            ft_strjoin(stash, line);
        }
        i++;
    }
    return (stash);
}


