/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:50:24 by fasharif          #+#    #+#             */
/*   Updated: 2022/09/01 14:41:20 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));  //(ft_strlen(save[i] - i + 1)  // If it ends with \n, you need to put both \n and \0, so allocate storage space by length + 2
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
// A function that returns a single line (one line only)
char	*ft_save(char *save) // or ft_strdup
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}
// Delete as many lines as read and return a new string
char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char)); // allocate memory ,'\0' because I have to add + 1
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0) // strchr is a function that checks if there is a matching character in a string. Checks if '\n' exists, and exits the loop if a newline character is encountered.
	{
		read_bytes = read(fd, buff, BUFFER_SIZE); // Read the string as much as BUFFER_SIZE using the read function and store it in the buffer. The length of the read string is stored in bytes.
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff); // Combines the read string in save and returns it
	}
	free(buff);
	return (save);
}
// Function to read and save the whole things
char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0) // ( || read(fd, NULL, 0) < 0) // If BUFFER_SIZE is 0 or negative, the read function cannot load the string properly, so exit If fd is negative then exit because it's not normal
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
