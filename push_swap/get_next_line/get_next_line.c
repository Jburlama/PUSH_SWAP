/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:23:36 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/17 22:39:35 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*buffer;
	int			bytes_read;

	line = NULL;
	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (check_nl(&str) == NULL)
		str = get_str_gnl(&str, &buffer, fd, &bytes_read);
	if (str == NULL || (*str == '\0'))
		return (free_all_gnl(&str, &buffer));
	while (check_nl(&str) == NULL && bytes_read != 0)
		str = get_str_gnl(&str, &buffer, fd, &bytes_read);
	if (str == NULL)
		return (free_all_gnl(&str, &buffer));
	line = fetch_line(&str);
	if (line == NULL)
		return (free_all_gnl(&str, NULL));
	str = update_str(&str);
	if (str == NULL)
		return (free_all_gnl(&str, &line));
	return (line);
}

char	*fetch_line(char **str)
{
	char	*line;
	int		i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
		i++;
	line = ft_calloc_gnl(i + 1);
	if (line == NULL)
		return (free_all_gnl(str, NULL));
	i = -1;
	while ((*str)[++i] != '\n' && (*str)[i] != '\0')
		line[i] = (*str)[i];
	if ((*str)[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_calloc_gnl(int size)
{
	char	*str;
	int		i;

	str = malloc(size);
	if (str == NULL)
		return (str);
	i = 0;
	while (i < size)
		str[i++] = '\0';
	return (str);
}

char	*free_all_gnl(char **s1, char **s2)
{
	if (s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 != NULL)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
