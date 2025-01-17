/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:50:20 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/17 10:39:29 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*add_buffer(char *str, char *buffer)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = malloc(ft_strlen(str) + ft_strlen(buffer) + 1);
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
	free(str);
	new_str[i + j] = '\0';
	return (new_str);
}

void	clear_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	j = 0;
	while (buffer[j + i])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*str;
	char		*line;
	int			size_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_strndup(buffer[fd], '\0');
	size_read = BUFFER_SIZE;
	while (size_read == BUFFER_SIZE && ft_strchr(buffer[fd], '\n') == 0)
	{
		size_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (size_read == -1)
			return (buffer[fd][0] = '\0', free(str), NULL);
		buffer[fd][size_read] = '\0';
		str = add_buffer(str, buffer[fd]);
		if (str == NULL)
			return (NULL);
	}
	if (str[0] == '\0')
		return (free(str), NULL);
	line = ft_strndup(str, '\n');
	free(str);
	clear_buffer(buffer[fd]);
	return (line);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int fd;
// 	int fd2;
// 	char *line;
// 	char *line2;

// 	fd = open("text.txt", O_RDONLY);
// 	fd2 = open("text2.txt", O_RDONLY);

// 	line = get_next_line(fd);
// 	if (fd == -1)
// 		return (printf("error"));
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	line2 = get_next_line(fd2);
// 	if (fd == -1)
// 		return (printf("error"));
// 	while (line2 != NULL)
// 	{
// 		printf("%s", line2);
// 		free(line2);
// 		line2 = get_next_line(fd2);
// 	}
// 	close(fd2);
// 	return (0);
// }