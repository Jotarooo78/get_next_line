/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:50:20 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/19 17:32:41 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clear_str(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	new_str = ft_strndup(str + i, '\n');
	free(str);
	return (new_str);
}

void	free_all_array(char *str)
{
	if (str != NULL)
		free(str);
}

char	*stock_and_replace(char *str, char *buf)
{
	char	*cache;

	cache = ft_strjoin(str, buf);
	if (cache == NULL)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (cache);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			size_read;
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	size_read = BUFFER_SIZE;
	if (str == NULL)
		str = ft_strndup("", '\n');
	while (size_read == BUFFER_SIZE && ft_strchr(str, '\n') == 0)
	{
		size_read = read(fd, buf, BUFFER_SIZE);
		if (size_read == -1)
		{
			free_all_array(str);
			return (NULL);
		}
		buf[size_read] = '\0';
		str = stock_and_replace(str, buf);
	}
	if (str[0] == '\0')
	{
		free_all_array(str);
		return (NULL);
	}
	line = ft_strndup(str, '\n');
	str = ft_clear_str(str);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	if (fd == -1)
// 		return (printf("error"));
// 	while (line != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }