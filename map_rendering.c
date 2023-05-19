/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 13:34:43 by rares         #+#    #+#                 */
/*   Updated: 2023/05/19 16:26:46 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	render_symbol_selector(t_game *game_data, size_t row, size_t col)
{
	if (game_data->map_as_array[row][col] == 'E')
	{
		if (mlx_image_to_window(game_data->mlx, game_data->images->exit_closed,
				PIXELS * col, PIXELS * row) == -1)
			raise_error("Error displaying the exit image.");
	}
	if (game_data->map_as_array[row][col] == 'C')
	{
		if (mlx_image_to_window(game_data->mlx, game_data->images->collectibles,
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

static void	render_player(t_game *game_data)
{
	if (mlx_image_to_window(game_data->mlx, game_data->images->player,
			PIXELS * game_data->player_col,
			PIXELS * game_data->player_row) == -1)
	{
		raise_error("Error displaying the player image.");
	}
}

void	render_moves_block(t_game *game_data)
{
	if (mlx_image_to_window(game_data->mlx, game_data->images->moves_block,
			(1 * PIXELS), (game_data->height - 1) * PIXELS) == -1)
		raise_error("Error displaying the player image.");
	if (mlx_image_to_window(game_data->mlx, game_data->images->moves_block,
			(2 * PIXELS), (game_data->height - 1) * PIXELS) == -1)
		raise_error("Error displaying the player image.");
}

void	fill_space(t_game *game_data)
{
	size_t		row;
	size_t		col;

	row = 0;
	while (row < game_data->height)
	{
		col = 0;
		while (col < game_data->width)
		{
			if (mlx_image_to_window(game_data->mlx, game_data->images->space,
					PIXELS * col, PIXELS * row) == -1)
			{
				raise_error("Error filling the background.");
			}
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
	fill_space(game_data);
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
	render_player(game_data);
	render_moves_block(game_data);
	display_moves(game_data);
	if (mlx_put_string(game_data->mlx, "MOVES:", ((1 * PIXELS) + 5),
			((game_data->height - 1) * PIXELS) + 22) == NULL)
	{
		raise_error("Error while displaying the MOVES string.");
	}
}
