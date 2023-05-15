/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_hooks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:24:29 by rares         #+#    #+#                 */
/*   Updated: 2023/05/15 17:53:44 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"


void	remove_collectible(t_game *game_data, size_t row, size_t col)
{
	char	**map;
	size_t	i;
	
	i = 0;
	map = game_data->map_as_array;
	row = 0;
	while(row < game_data->height)
	{
		col = 0;
		while (col < game_data->width)
		{
			if ()
		}
	game_data->images->collectible->instances[i].enabled = false;
			
}

void	move_up(t_game *game_data)
{
	char		**map;
	size_t		row;
	size_t		col;

	row = game_data->player_row;
	col = game_data->player_col;
	map = game_data->map_as_array;
	
	if (map[row - 1][col] == '1' || (map[row - 1][col] == 'E' && game_data->can_exit == 0))
		return ;
	if (map[row - 1][col] == 'C')
	{
		game_data->collected++;
		remove_collectible(game_data, row, col);
	}
	game_data->player_row--;
	game_data->images->player->instances[0].y -= PIXELS;
}

void	move_hook_callback(mlx_key_data_t keydata, void *data)
{
	t_game	*game_data;
	
	game_data = (t_game *)data;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game_data->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game_data);
	// if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	// 	//move down
	// if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	// 	//move left
	// if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	// 	//move right
}