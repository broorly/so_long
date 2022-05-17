/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:08:22 by mrafik            #+#    #+#             */
/*   Updated: 2022/05/17 15:12:03 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
typedef struct data
{
	void	*mlx;
	void	*mlx_win;
	char	**matrix;
	void	*img1;
	void	*img0;
	void	*imgP;
	void	*imgE;
	void	*imgC;
	int		height;
	int		xpos;
	int		ypos;
	int		width;
}				t_data;


size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int check (t_data *data);
int ft_matrix(t_data *data);

#endif