/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:41:30 by mrafik            #+#    #+#             */
/*   Updated: 2022/05/20 19:19:29 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_put_e(t_data *data, int i, int j)
{
	if (ft_count(data, 'C') == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imge1, i * 64, j * 64);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imge, i * 64, j * 64);
	i++;
	return (i);
}

int	ft_pu_p_c(t_data *data, int i, int j)
{
	if (data->matrix[j][i] == 'P')
	{
		data->xpos = i;
		data->ypos = j;
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img0, i * 64, j * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgp, i * 64, j * 64);
		i++;
	}
	if (data->matrix[j][i] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img0, i * 64, j * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgc, i * 64, j * 64);
		i++;
	}
	return (i);
}

int	ft_put_0_1(t_data *data, int i, int j)
{
	if (data->matrix[j][i] == '1')
	{
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->img1, i * 64, j * 64);
		i++;
	}
	else if (data->matrix[j][i] == '0')
	{	
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->img0, i * 64, j * 64);
		i++;
	}
	return (i);
}

void	ft_render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			if (data->matrix[j][i] == '1' || data->matrix[j][i] == '0')
				i = ft_put_0_1(data, i, j);
			else if (data->matrix[j][i] == 'P' || data->matrix[j][i] == 'C')
				i = ft_pu_p_c(data, i, j);
			else if (data->matrix[j][i] == 'E')
				i = ft_put_e(data, i, j);
		}
		j++;
	}
}

int	main(void)
{
	int		width;
	int		height;
	t_data	data;

	if (!ft_matrix(&data))
		return (0);
	if (!check(&data))
		return (0);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx,
			64 * data.width, 64 * data.height, "yo");
	data.img1 = mlx_xpm_file_to_image(data.mlx, "1.xpm", &height, &width);
	data.img0 = mlx_xpm_file_to_image(data.mlx, "0.xpm", &height, &width);
	data.imgp = mlx_xpm_file_to_image(data.mlx, "P.xpm", &height, &width);
	data.imgc = mlx_xpm_file_to_image(data.mlx, "C.xpm", &height, &width);
	data.imge = mlx_xpm_file_to_image(data.mlx, "E.xpm", &height, &width);
	data.imge1 = mlx_xpm_file_to_image(data.mlx, "E1.xpm", &height, &width);
	ft_render(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx);
}
