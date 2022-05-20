/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_so_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:16:19 by mrafik            #+#    #+#             */
/*   Updated: 2022/05/20 19:12:46 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_up(t_data *data, int x)
{
	if (data->matrix[data->ypos - 1][data->xpos] != '1'
		&& ft_count(data, 'C') != x)
	{
		if (ft_count(data, 'C') != x
			&& data->matrix[data->ypos - 1][data->xpos] != 'E')
		{
			data->matrix[data->ypos - 1][data->xpos] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
		}
	}
	else if (ft_count(data, 'C') == 0)
		x = 0;
	if (data->matrix[data->ypos - 1][data->xpos] == 'E'
		&& ft_count(data, 'C') == 0)
		exit(0);
}

void	ft_down(t_data *data, int x)
{
	if (data->matrix[data->ypos + 1][data->xpos] != '1'
		&& ft_count(data, 'C') != x)
	{
		if (ft_count(data, 'C') != x
			&& data->matrix[data->ypos + 1][data->xpos] != 'E')
		{
			data->matrix[data->ypos + 1][data->xpos] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
		}
	}
	else if (ft_count(data, 'C') == 0)
		x = 0;
	if (data->matrix[data->ypos + 1][data->xpos] == 'E'
		&& ft_count(data, 'C') == 0)
		exit(0);
}

void	ft_left(t_data *data, int x)
{
	if (data->matrix[data->ypos][data->xpos - 1] != '1')
	{
		if (ft_count(data, 'C') != x
			&& data->matrix[data->ypos][data->xpos - 1] != 'E')
		{
			data->matrix[data->ypos][data->xpos - 1] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
		}
		else if (ft_count(data, 'C') == 0)
			x = 0;
		if (data->matrix[data->ypos][data->xpos - 1] == 'E'
			&& ft_count(data, 'C') == 0)
			exit(0);
	}
}

void	ft_right(t_data *data, int x)
{
	if (data->matrix[data->ypos][data->xpos + 1] != '1')
	{
		if (data->matrix[data->ypos][data->xpos + 1] != 'E'
			&& ft_count(data, 'C') != x)
		{
			data->matrix[data->ypos][data->xpos + 1] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
		}
	}
	else if (ft_count(data, 'C') == 0)
		x = 0;
	if (data->matrix[data->ypos][data->xpos + 1] == 'E'
		&& ft_count(data, 'C') == 0)
		exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	int	x;

	x = -1;
	if (keycode == 13)
		ft_up(data, x);
	else if (keycode == 1)
		ft_down(data, x);
	else if (keycode == 0)
		ft_left(data, x);
	else if (keycode == 2)
		ft_right(data, x);
	ft_render(data);
	return (0);
}
