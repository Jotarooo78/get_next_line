#include "get_next_line.h"

char	*fill_and_clean_str(char *str)
{
	int	i;
	char *new_str;

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

char	*ft_free_all(char *str)
{
	str = NULL;
	free(str);
	return (str);
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
			ft_free_all(str);
			return (NULL);
		}
		buf[size_read] = '\0';
		str = ft_strjoin(str, buf);
	}
	if (str[0] == '\0')
	{
		ft_free_all(str);
		return (NULL);
	}
	line = ft_strndup(str, '\n');
	str = fill_and_clean_str(str);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	if (fd == -1)
		return (printf("error"));
	while (line != NULL)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}	
	close(fd);
	return (0);
}

