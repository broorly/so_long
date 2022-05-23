/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_so_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:16:19 by mrafik            #+#    #+#             */
/*   Updated: 2022/05/22 13:59:20 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_up(t_data *data, int x, int move)
{
	if (data->matrix[data->ypos - 1][data->xpos] != '1'
		&& ft_count(data, 'C') != x)
	{
		if (ft_count(data, 'C') != x
			&& data->matrix[data->ypos - 1][data->xpos] != 'E')
		{
			data->matrix[data->ypos - 1][data->xpos] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
			move++;
			ft_printf("move:%d\n", move);
		}
	}
	else if (ft_count(data, 'C') == 0)
		x = 0;
	if (data->matrix[data->ypos - 1][data->xpos] == 'E'
		&& ft_count(data, 'C') == 0)
	{
		ft_printf("move:%d\nyou win\n", ++move);
		exit(0);
	}
	return (move);
}

int	ft_down(t_data *data, int x, int move)
{
	if (data->matrix[data->ypos + 1][data->xpos] != '1'
		&& ft_count(data, 'C') != x)
	{
		if (ft_count(data, 'C') != x
			&& data->matrix[data->ypos + 1][data->xpos] != 'E')
		{
			data->matrix[data->ypos + 1][data->xpos] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
			move++;
			ft_printf("move:%d\n", move);
		}
	}
	else if (ft_count(data, 'C') == 0)
		x = 0;
	if (data->matrix[data->ypos + 1][data->xpos] == 'E'
		&& ft_count(data, 'C') == 0)
	{
		ft_printf("move:%d\nyou win\n", ++move);
		exit(0);
	}
	return (move);
}

int	ft_left(t_data *data, int x, int move)
{
	if (data->matrix[data->ypos][data->xpos - 1] != '1')
	{
		if (ft_count(data, 'C') != x
			&& data->matrix[data->ypos][data->xpos - 1] != 'E')
		{
			data->matrix[data->ypos][data->xpos - 1] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
			move++;
			ft_printf("move:%d\n", move);
		}
		else if (ft_count(data, 'C') == 0)
			x = 0;
		if (data->matrix[data->ypos][data->xpos - 1] == 'E'
			&& ft_count(data, 'C') == 0)
		{
			ft_printf("move:%d\nyou win\n", ++move);
			exit(0);
		}
	}
	return (move);
}

int	ft_right(t_data *data, int x, int move)
{
	if (data->matrix[data->ypos][data->xpos + 1] != '1')
	{
		if (data->matrix[data->ypos][data->xpos + 1] != 'E'
			&& ft_count(data, 'C') != x)
		{
			data->matrix[data->ypos][data->xpos + 1] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
			move++;
			ft_printf("move:%d\n", move);
		}
	}
	else if (ft_count(data, 'C') == 0)
		x = 0;
	if (data->matrix[data->ypos][data->xpos + 1] == 'E'
		&& ft_count(data, 'C') == 0)
	{
		ft_printf("move:%d\nyou win\n", ++move);
		exit(0);
	}
	return (move);
}

int	key_hook(int keycode, t_data *data)
{
	int			x;
	static int	move = 0;

	x = -1;
	if (keycode == 53 || keycode < 0)
		exit(0);
	if (keycode == 13)
		move = ft_up(data, x, move);
	else if (keycode == 1)
		move = ft_down(data, x, move);
	else if (keycode == 0)
		move = ft_left(data, x, move);
	else if (keycode == 2)
		move = ft_right(data, x, move);
	ft_render(data);
	return (0);
}
