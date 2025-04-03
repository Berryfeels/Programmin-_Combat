/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:24:46 by mcheragh          #+#    #+#             */
/*   Updated: 2025/03/03 14:44:19 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Helper function to extract a line from the archive buffer
static char	*line_from_archive(char *archive)
{
	int		i;
	char	*line;

	i = 0;
	if (!archive || !archive[i])
		return (NULL);
	while (archive[i] && archive[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (archive[i] && archive[i] != '\n')
	{
		line[i] = archive[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// Main function to get the next line from a file descriptor
char	*get_next_line(int fd)
{
	static char	*archive[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	archive[fd] = read_to_archive(fd, archive[fd]);
	if (!archive[fd])
		return (NULL);
	line = line_from_archive(archive[fd]);
	if (!line)
	{
		free(archive[fd]);
		archive[fd] = NULL;
		return (NULL);
	}
	archive[fd] = update_archive(archive[fd]);
	if (!archive[fd])
	{
		free(archive[fd]);
		archive[fd] = NULL;
	}
	return (line);
}
