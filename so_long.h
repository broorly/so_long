/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:16:16 by mrafik            #+#    #+#             */
/*   Updated: 2022/05/19 17:27:13 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
#include <stdio.h>
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
	void	*imgE1;
	int		height;
	int		xpos;
	int		ypos;
	int		width;
	int		p;
	int		e;
	int		c;
}				t_data;


size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int check (t_data *data);
int ft_matrix(t_data *data);
int ft_count(t_data *data, char s);
int	key_hook(int keycode, t_data *data);
void ft_render(t_data *data);
void ft_right(t_data *data, int x);
void ft_left(t_data *data, int x);
void ft_down(t_data *data,int x);
void ft_up(t_data *data ,int x);
int legal(char *str, t_data *data);
int ft_count(t_data *data, char s);

#endif