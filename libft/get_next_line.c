/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:28:12 by scornhol          #+#    #+#             */
/*   Updated: 2021/11/04 13:29:13 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: get_next_line
 * Prototype: char *get_next_line(int fd);
 * Turn in files: get_next_line.c, get_next_line_utils.c, get_next_line.h
 * Parameters: File descriptor to read from
 * Return value: Read line:  correct behavior
 * 				 NULL: nothing else to read or an error occurred
 * External functs.: read, malloc, free
 * Description: Write a function which returns a line read from
 * 				a file descriptor								 */

#include "libft.h"

char	*ft_get_str(char **rest, char **line)
{
	char	*new_rest;
	size_t	i;

	i = 0;
	new_rest = NULL;
	while ((*(*rest + i) != '\n') && (*(*rest + i) != '\0'))
		i++;
	if (*(*rest + i) == '\n')
	{
		i++;
		*line = ft_substr(*rest, 0, i);
		new_rest = ft_strdup(*rest + i);
	}
	else
		*line = ft_strdup(*rest);
	free(*rest);
	*rest = NULL;
	return (new_rest);
}

ssize_t	ft_read_file(int fd, char **buffer, char **rest, char **line)
{
	char	*tmp;
	ssize_t	nbr;

	nbr = 1;
	while (!ft_strchr(*rest, '\n') && nbr)
	{
		nbr = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[nbr] = '\0';
		tmp = *rest;
		*rest = ft_strjoin(tmp, *buffer);
		free(tmp);
	}
	free(*buffer);
	*buffer = NULL;
	*rest = ft_get_str(rest, line);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	return (nbr);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*buffer;
	char		*line;
	ssize_t		num;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!rest)
		rest = ft_strdup("");
	num = ft_read_file(fd, &buffer, &rest, &line);
	if (num == 0 && !line)
		return (NULL);
	return (line);
}
