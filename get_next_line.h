/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:20:28 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/16 11:16:11 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*add_buffer(char *str, char *buffer);
void    copy_rest(char *dest, char *src);
char	*dup_line(char *src);
int     ft_strlen(const char *str);
int	    ft_strchr(char *str, char c);
char    *ft_strdup(char *str);
char	*get_next_line(int fd);

#endif