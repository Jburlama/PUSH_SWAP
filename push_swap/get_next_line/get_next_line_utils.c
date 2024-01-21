/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:26:25 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/17 19:10:58 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_str_gnl(char **str, char **buffer, int fd, int *bytes_read)
{
	while (*bytes_read > 0)
	{
		*buffer = ft_calloc_gnl(BUFFER_SIZE + 1);
		if (*buffer == NULL)
			return (free_all_gnl(str, NULL));
		*bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (*bytes_read < 0)
			return (free_all_gnl(buffer, str));
		(*buffer)[*bytes_read] = '\0';
		if (*bytes_read == 0 && !(*str))
			return (free_all_gnl(buffer, str));
		*str = strappend(str, buffer);
		if (str == NULL)
			return (free_all_gnl(buffer, NULL));
		if (check_nl(str))
			return (*str);
	}
	return (*str);
}

char	*update_str(char **str)
{
	char	*update_str;
	int		i;
	int		j;
	int		k;

	i = 0;
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\0')
	{
		update_str = ft_calloc_gnl(1);
		if (update_str == NULL)
			return (free_all_gnl(str, NULL));
		free_all_gnl(str, NULL);
		return (update_str);
	}
	k = i;
	j = ft_strlen_gnl((*str) + i);
	update_str = ft_calloc_gnl(j);
	j = -1;
	while ((*str)[++k] != '\0')
		update_str[++j] = (*str)[k];
	free_all_gnl(str, NULL);
	return (update_str);
}

char	*check_nl(char **str)
{
	int	i;

	i = 0;
	if (*str == NULL)
		return (NULL);
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '\n')
			return ((*str) + i);
		i++;
	}
	return (NULL);
}

char	*strappend(char **str, char **buffer)
{
	char	*strappend;
	int		i;
	int		j;

	if (*str == NULL)
		return (ft_strcpy(buffer));
	i = 0;
	while ((*str)[i] != '\0')
		i++;
	j = 0;
	while ((*buffer)[j] != '\0')
		j++;
	strappend = ft_calloc_gnl(i + j + 1);
	if (strappend == NULL)
		return (free_all_gnl(str, buffer));
	i = -1;
	while ((*str)[++i] != '\0')
		strappend[i] = (*str)[i];
	j = -1;
	while ((*buffer)[++j] != '\0')
		strappend[i++] = (*buffer)[j];
	free_all_gnl(str, buffer);
	return (strappend);
}

char	*ft_strcpy(char **buffer)
{
	char	*strcpy;
	int		i;

	i = 0;
	while ((*buffer)[i] != '\0')
		i++;
	strcpy = ft_calloc_gnl(i + 1);
	if (strcpy == NULL)
		return (free_all_gnl(buffer, NULL));
	i = -1;
	while ((*buffer)[++i] != '\0')
		strcpy[i] = (*buffer)[i];
	free_all_gnl(buffer, NULL);
	return (strcpy);
}
