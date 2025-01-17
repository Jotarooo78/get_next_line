/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:34:01 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/06 18:04:07 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

char	*get_next_line(int fd);
char	*add_buffer(char *str, char *buffer);
void	clear_buffer(char *buffer);
int		ft_strchr(char *str, char c);
size_t	ft_strlen(char *str);
char	*ft_strndup(char *str, char c);

#endif