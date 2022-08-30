/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:58:24 by fasharif          #+#    #+#             */
/*   Updated: 2022/08/30 16:58:44 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	int fd2;
	char *line;
	char *line2;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	printf("fd: %d\n", fd);
	printf("fd2: %d\n", fd2);

	line = get_next_line(fd);
	printf("%s", line);
	line2 = get_next_line(fd2);
	printf("%s", line2);

	free(line);
	free(line2);

	line = get_next_line(fd);
	printf("%s", line);
	line2 = get_next_line(fd2);
	printf("%s", line2);

	free(line);
	free(line2);
	close(fd);
	close(fd2);
	return (0);
}