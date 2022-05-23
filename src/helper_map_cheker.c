/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_map_cheker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:23:55 by mrafik            #+#    #+#             */
/*   Updated: 2022/05/23 16:09:13 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count(t_data *data, char s)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	count = 0;
	while (data->matrix[x])
	{
		y = 0;
		while (data->matrix[x][y])
		{
			if (data->matrix[x][y] == s)
					count++;
				y++;
		}
			x++;
	}
	return (count);
}

int	legal(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0'
			&& str[i] != 'C' && str[i] != 'P' && str[i] != 'E')
			return (0);
		if (str[i] == 'C')
			data->c++;
		if (str[i] == 'E')
			data->e++;
		if (str[i] == 'P')
			data->p++;
		i++;
	}
	return (1);
}

int	type_check(char *map)
{
	char	*str;

	str = ft_strchr(map, '.');
	if (!str)
		return (0);
	else if (ft_strcmp(str, ".ber"))
		return (0);
	if (ft_strlen(map) <= 4)
		return (0);
	return (1);
}
