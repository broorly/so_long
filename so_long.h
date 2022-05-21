/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:16:16 by mrafik            #+#    #+#             */
/*   Updated: 2022/05/21 14:13:05 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include "ft_printf.h"

typedef struct data
{
	void	*mlx;
	void	*mlx_win;
	char	**matrix;
	void	*img1;
	void	*img0;
	void	*imgp;
	void	*imge;
	void	*imgc;
	void	*imge1;
	int		height;
	int		xpos;
	int		ypos;
	int		width;
	int		p;
	int		e;
	int		c;
}				t_data;
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		check(t_data *data);
int		ft_matrix(t_data *data, char *map);
int		ft_count(t_data *data, char s);
int		key_hook(int keycode, t_data *data);
int		ft_right(t_data *data, int x, int move);
int		ft_left(t_data *data, int x, int move);
int		ft_down(t_data *data, int x, int move);
int		ft_up(t_data *data, int x, int move);
void	ft_render(t_data *data);
int		legal(char *str, t_data *data);
int		ft_count(t_data *data, char s);
void	height_width(t_data *data);

#endif