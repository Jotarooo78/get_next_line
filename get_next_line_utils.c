/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:27:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/15 16:50:04 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static  int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

static int ft_strchr(char *str, char c)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0); 
}

static char    *ft_strdup(char *str)
{
    char *dup;
    int i;

    dup = malloc(sizeof(char) * (ft_strlen(str)+ 1));
    if (dup == NULL)
        return (NULL);
    i = 0;
    while (str[i])
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

static char    *ft_strjoin(char *start, char *end)
{
    char    *new_str;
    int i;
    int j;
    
    new_str = malloc(sizeof(char) * (ft_strlen(start) + ft_strlen(end) + 1));
    if (new_str == NULL)
        return (NULL);
    i = 0;
    while (start[i])
    {
        new_str[i] = start[i];
        i++;
    }
    j = 0;
    while (end[j])
    {
        new_str[i + j] = end[j];
        j++;
    }
    free(start);
    new_str[i + j] = '\0';
    return (new_str);
}