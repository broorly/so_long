
#include"get_next_line.h"
#include<mlx.h>

void ft_render(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(j  < data->height)
	{
		i = 0;
		while(i < data->width)
		{
			if( data->matrix[j][i]== '1')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img1, i * 80 , j* 80 );
				i++;
			}
			else if(data->matrix[j][i]== '0')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img0, i * 80 , j* 80 );
				i++;
			}
			
			if( data->matrix[j][i]== 'P')
			{
				data->xpos = i;
				data->ypos = j;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img0, i * 80 , j* 80 );
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgP, i * 80 , j* 80 );
				i++;
			}
			if( data->matrix[j][i]== 'E')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img0, i * 80 , j* 80 );
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgE, i * 80 , j* 80 );
				i++;
			}
			else if( data->matrix[j][i] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img0, i * 80 , j* 80 );
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgC, i * 80 , j* 80 );
				i++;
			}
			
		}
		j++;
	}
}

int	key_hook(int keycode, t_data *data)
{
	static int	i = 0;
	if(keycode == 13)
	{
		if(data->matrix[data->ypos - 1][data->xpos]!= '1')
		{
			data->matrix[data->ypos - 1][data->xpos] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
		}
		
	}
	else if(keycode == 1)
	{
		if(data->matrix[data->ypos + 1][data->xpos]!= '1')
		{
			data->matrix[data->ypos + 1][data->xpos] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
		}
		
	}
	else if(keycode == 0 )
	{
		if(data->matrix[data->ypos][data->xpos - 1]!= '1')
		{
			data->matrix[data->ypos][data->xpos - 1] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
		}
		
	}
	else if(keycode == 2 )
	{
		if(data->matrix[data->ypos][data->xpos + 1]!= '1')
		{
			data->matrix[data->ypos][data->xpos + 1] = 'P';
			data->matrix[data->ypos][data->xpos] = '0';
		}
	}
	ft_render(data);
	return (0);
}

int main(void)
{
	int width;
	int height;

	t_data data;

	if(!ft_matrix(&data))
		return 0;
	if(!check(&data))
		return 0;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 80 * data.width, 80 * data.height, "Hello world!");
	data.img1 = mlx_xpm_file_to_image(data.mlx, "1.xpm", &height, &width);
	data.img0 = mlx_xpm_file_to_image(data.mlx, "0.xpm", &height, &width);
	data.imgP= mlx_xpm_file_to_image(data.mlx, "P.xpm", &height, &width);
	data.imgC = mlx_xpm_file_to_image(data.mlx, "C.xpm", &height, &width);
	data.imgE = mlx_xpm_file_to_image(data.mlx, "E.xpm", &height, &width);
	
	// mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, i * 50 , j* 50 );
	ft_render(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx);
}