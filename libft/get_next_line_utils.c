/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:19:51 by lsasse            #+#    #+#             */
/*   Updated: 2025/03/03 14:44:13 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to update the archive after reading a line
char	*update_archive(char *archive)
{
	int		i;
	char	*new_archive;

	i = 0;
	if (!archive || !archive[i])
	{
		free(archive);
		return (NULL);
	}
	while (archive[i] && archive[i] != '\n')
		i++;
	if (!archive[i])
	{
		free(archive);
		return (NULL);
	}
	new_archive = ft_strdup(archive + i + 1);
	free(archive);
	return (new_archive);
}

// Function to read data into the archive buffer from the file descriptor
static char	*handle_buffer_allocation(int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		printf("Error: malloc failed for buffer\n");
		return (NULL);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*read_to_archive(int fd, char *archive)
{
	char	*buffer;
	char	*new_archive;

	buffer = handle_buffer_allocation(fd);
	if (!buffer)
		return (archive);
	if (!archive)
		new_archive = ft_strdup(buffer);
	else
		new_archive = ft_strjoin(archive, buffer);
	free(buffer);
	if (!new_archive)
	{
		printf("Error: malloc failed for archive\n");
		return (NULL);
	}
	free(archive);
	return (new_archive);
}
