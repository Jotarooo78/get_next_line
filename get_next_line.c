/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:20:25 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/16 11:15:50 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_rest(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
        if (src[i] == '\n')
        {
            i++;
            break ;
        }
        i++;
    }
	while (src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
}

char	*add_buffer(char *str, char *buffer)
{
	char	*new_str;
	int	i;
	int	j;

	new_str = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buffer) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		new_str[i + j] = buffer[j];
		j++;
	}
	new_str[i + j] = '\0';
    free(str);
	return (new_str);
}

char	*dup_line(char *src)
{
    char	*dup;
	int		i;

	i = 0;
    while (src[i] != '\n')
		i++;
	dup = malloc((i + 2) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
		if (src[i] == '\n')
			break ;
	}
	dup[i] = '\0';
	free(src);
	return (dup);
}

char	*get_next_line(int fd)
{
    static char	buffer[BUFFER_SIZE + 1];
	int			size_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	size_read = BUFFER_SIZE;
	line = ft_strdup(buffer);
	while (ft_strchr(buffer, '\n') == 0 && size_read == BUFFER_SIZE)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read <= 0)
			if (buffer[0] == '\0' && line[0] ==  '\0')
				return (free(line), NULL);
        buffer[size_read] = '\0';
		line = add_buffer(line, buffer);
	}
	if (line[0] == '\0')
		return (free(line), NULL);
	if (ft_strchr(line, '\n') == 0)
		return (buffer[0] = '\0', line);
	return (copy_rest(buffer, line), line = dup_line(line));
}

#include <stdio.h>
int	main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}