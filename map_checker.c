/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:01:59 by mrafik            #+#    #+#             */
/*   Updated: 2022/05/18 18:48:15 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
# include <fcntl.h>

#include"so_long.h"

char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

int	wall(t_data *data)
{
	int x;

	x = 0;
	while(x < data->height)
	{
		if (data->matrix[x][0] != '1' || data->matrix[x][data->width - 1] != '1')
			return (0);
		x++;
	}
	return(1);
}

int legal(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'P' && str[i] != 'E')
			return (0);
		if(str[i] == 'C')
			data->c++;
		if(str[i] == 'E')
			data->e++;
		if(str[i] == 'P')
			data->p++;
		i++;
	}
	return (1);
}

int	head(char **matrix)
{
	int	x;
	int	len;
	x = 0;
	// if(!matrix[0][x] || !matrix[len][x])
	// 	return(0);
	len = 0;
	while (matrix[len])
		len++;
	while (matrix[0][x] != '\0' || matrix[len-1][x] != '\0')
	{
		if(matrix[0][x] != '1' || matrix[len-1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}
int ft_matrix(t_data *data)
{
	char	*str;
	char	*all;
	int		x;
	int		fd;
	
	x = 0;
	all = NULL;
	fd = open("map.ber",0);
	str = get_next_line(fd);
	while (str)
	{
		all = ft_strjoin(all,str);
		free(str);
		str = get_next_line(fd);
	}
	if (all[ft_strlen(all) - 1] == '\n' )
		return (0); 
	data->matrix = ft_split(all, '\n');
	if (!data->matrix)
		return (0);
	while (data->matrix[x])
		x++;
	data->height = x;
	data->width = ft_strlen(data->matrix[0]);
	return (1);
}


int check (t_data *data)
{
	int i;

	i = 0;
	data->c = 0;
	data->p = 0;
	data->e = 0;
	while (i < data->height)
	{
		if (ft_strlen(data->matrix[i]) != data->width)
			return (0);
		i++;
	}
	i = 0;
	while (data->matrix[i])
	{
		if (legal(data->matrix[i], data) != 1)
			return (0);
		i++;
	}
	if (wall(data) != 1 || head(data->matrix) != 1)
		return (0);
	return (1);
}
// #include<stdio.h>

// int main()
// {
// 	t_data data;
// 	int x;
// 	int i;

// 	i = 0;
// 	if(!ft_matrix(&data))
// 		return 0;
// 	while(data.matrix[i])
// 	{
// 		printf("%s\n", data.matrix[i]);
// 		i++;
// 	}
// 	printf("%d %d\n", data.width, data.height);
// 	x = check(&data);
// 	printf("%d",x);
// }

