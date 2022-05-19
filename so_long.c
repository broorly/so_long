
#include"so_long.h"
#include<mlx.h>

int	ft_putE(t_data *data, int i,int j)
{
	if(ft_count(data,'C') == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgE1, i * 64 , j* 64 );
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgE, i * 64 , j* 64 );
	i++;
	return(i);
}
int ft_putP(t_data *data, int i , int j)
{
	data->xpos = i;
	data->ypos = j;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img0, i * 64 , j* 64 );
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgP, i * 64 , j* 64 );
	i++;
	return(i);
}
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
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img1, i * 64 , j* 64 );
				i++;
			}
			else if(data->matrix[j][i]== '0')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img0, i * 64 , j* 64 );
				i++;
			}
			if( data->matrix[j][i]== 'P')
				 i = ft_putP(data,i ,j);
			if( data->matrix[j][i]== 'E')
				i = ft_putE(data,i,j);
			else if( data->matrix[j][i] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img0, i * 64 , j* 64 );
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgC, i * 64 , j* 64 );
				i++;
			}	
		}
		j++;
	}
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
	data.mlx_win = mlx_new_window(data.mlx, 64 * data.width, 64 * data.height, "Hello world!");
	data.img1 = mlx_xpm_file_to_image(data.mlx, "1.xpm", &height, &width);
	data.img0 = mlx_xpm_file_to_image(data.mlx, "0.xpm", &height, &width);
	data.imgP= mlx_xpm_file_to_image(data.mlx, "P.xpm", &height, &width);
	data.imgC = mlx_xpm_file_to_image(data.mlx, "C.xpm", &height, &width);
	data.imgE = mlx_xpm_file_to_image(data.mlx, "E.xpm", &height, &width);
	data.imgE1 = mlx_xpm_file_to_image(data.mlx, "E1.xpm", &height, &width);
	ft_render(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx);
}