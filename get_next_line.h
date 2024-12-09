/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:34:01 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/09 15:31:55 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL
# define GNL

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

# define BUFFER_SIZE 5

char    *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);

#endif