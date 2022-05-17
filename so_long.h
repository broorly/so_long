#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include<mlx.h>
#include"get_next_line.h"

// typedef struct first
// {
// 	void s;
// 	char	**matrix;
// 	int		height;
// 	int		width;
// }				t_first;


size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int ft_matrix(t_data *data);
int check (t_data *data);

#endif