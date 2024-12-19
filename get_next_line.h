/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:34:01 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/19 16:24:38 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL
# define GNL

# include <fcntl.h>
# include <limits.h>
# include <stdio.h> // a supprimer
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
char	*fill_and_clean_str(char *str);
char	*ft_strndup(char *buf, int c);
// void	*ft_calloc(size_t nmemb, size_t size);
// void	*ft_memset(void *s, int c, size_t n);
int		ft_strlen(char *s);

#endif