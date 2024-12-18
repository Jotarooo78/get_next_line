/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:50:20 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/18 17:42:07 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_str(char *str)
{
	int	i;

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
	if (str != NULL)
	{
		str = ft_strndup(str + i, '\n');
	}
	return (str);
}

char	*return_read(char buf[BUFFER_SIZE]);

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			size_read;
	static char	*str;
	char		*line;

	size_read = BUFFER_SIZE;
	if (str == NULL)
		str = ft_strndup("", '\n');
	while (size_read == BUFFER_SIZE && ft_strchr(str, '\n') == 0)
	{
		size_read = read(fd, buf, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(str);
			return (NULL);
		}
		buf[size_read] = '\0';
		str = ft_strjoin(str, buf);
	}
	line = ft_strndup(str, '\n');
	str = ft_clean_str(str);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	close(fd);
	return (0);
}
