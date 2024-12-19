/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:33:21 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/19 16:49:52 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	while (s1[i] && s1)
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strndup(char *buf, int c)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(buf) + 1));
	if (dup == NULL)
		return (NULL);
	while (buf[i] && buf[i] != c)
	{
		dup[i] = buf[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*res;

// 	if (nmemb == INT_MAX && size == INT_MAX)
// 		return (NULL);
// 	res = malloc(nmemb * size);
// 	if (res == NULL)
// 		return (NULL);
// 	ft_memset(res, 0, nmemb * size);
// 	return (res);
// }

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t i;
// 	char *str;

// 	i = 0;
// 	str = (char *)s;
// 	while (n)
// 	{
// 		str[i] = (char)c;
// 		i++;
// 		n--;
// 	}
// 	return (str);
// }