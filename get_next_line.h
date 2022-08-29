#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 1024
// # endif
// # include <unistd.h>
// # include <stdlib.h>

// typedef struct file
// {
// 	int			fd;
// 	char		rb_ar[BUFFER_SIZE];
// 	char		*str;
// 	ssize_t		rb_size;
// 	size_t		rb_pos;
// 	size_t		s_capacity;
// 	size_t		s_size;
// 	struct file	*next;
// }

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *save);
char	*ft_save(char *save);
char	*ft_get_line(char *save);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
