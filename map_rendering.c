/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 13:34:43 by rares         #+#    #+#                 */
/*   Updated: 2023/05/15 11:24:11 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// void	render_symbols_1(t_game *game_data)
// {
// 	char		**map;
// 	size_t		row;
// 	size_t		col;

// 	row = 0;
// 	map = game_data->map_as_array;
// 	while(row < game_data->height)
// 	{
// 		col = 0;
// 		while(col < game_data->width)
// 		{
// 			if (map[row][col] == '1')
// 				if (mlx_image_to_window(game_data->mlx, game_data->images->wall, 
// 					PIXELS * col, PIXELS * row) == -1)
// 					raise_error("Error displaying the wall image.");
// 			col++;
// 		}
// 		row++;
// 	}
// }

void	render_symbol_selector(t_game *game_data, size_t row, size_t col)
{
	if (game_data->map_as_array[row][col] == 'P')
	{
		if (mlx_image_to_window(game_data->mlx, game_data->images->player,
				PIXELS * col, PIXELS * row) == -1)
			raise_error("Error displaying the player image.");
	}
	if (game_data->map_as_array[row][col] == 'E')
	{
		if (mlx_image_to_window(game_data->mlx, game_data->images->exit_closed,
				PIXELS * col, PIXELS * row) == -1)
			raise_error("Error displaying the exit image.");
	}
	if (game_data->map_as_array[row][col] == 'C')
	{
		if (mlx_image_to_window(game_data->mlx, game_data->images->collectible,
				PIXELS * col, PIXELS * row) == -1)
			raise_error("Error displaying the collectible image.");
	}
	if (game_data->map_as_array[row][col] == '1')
	{
		if (mlx_image_to_window(game_data->mlx, game_data->images->wall,
				PIXELS * col, PIXELS * row) == -1)
			raise_error("Error displaying the wall image.");
	}
}

void	fill_space(t_game *game_data)
{
	size_t		row;
	size_t		col;

	row = 1;
	while (row < game_data->height - 1)
	{
		col = 1;
		while (col < game_data->width - 1)
		{
			if (mlx_image_to_window(game_data->mlx, game_data->images->space, PIXELS * col, PIXELS * row) == -1)
				raise_error("Error filling the background.");
			col++;
		}
		row++;
	}
}

void	render_map(t_game *game_data)
{
	size_t		row;
	size_t		col;

	row = 0;
	while (row < game_data->height)
	{
		col = 0;
		while (col < game_data->width)
		{
			render_symbol_selector(game_data, row, col);
			col++;
		}
		row++;
	}

}