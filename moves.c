/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 17:27:52 by rares         #+#    #+#                 */
/*   Updated: 2023/11/27 15:20:43 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	remove_collectible(t_game *game_data, int row, int col)
{
	size_t	i;

	i = 0;
	col = col * PIXELS;
	row = row * PIXELS;
	while (i < game_data->images->collectibles->count)
	{
		if (game_data->images->collectibles->instances[i].x == col
			&& game_data->images->collectibles->instances[i].y == row)
		{
			if (game_data->images->collectibles->instances[i].enabled == true)
				game_data->collected++;
			game_data->images->collectibles->instances[i].enabled = false;
		}
		i++;
	}	
}

void	move_up(t_game *game_data)
{
	char		**map;
	size_t		row;
	size_t		col;

	row = game_data->player_row;
	col = game_data->player_col;
	map = game_data->map_as_array;
	if (map[row - 1][col] == '1' ||
		(map[row - 1][col] == 'E' && game_data->can_exit == 0))
	{	
		return ;
	}
	if (map[row - 1][col] == 'C')
		remove_collectible(game_data, row - 1, col);
	game_data->player_row--;
	game_data->images->player->instances[0].y -= PIXELS;
	game_data->moves++;
	ft_printf("Moves: %i\n", game_data->moves);
}

void	move_down(t_game *game_data)
{
	char		**map;
	size_t		row;
	size_t		col;

	row = game_data->player_row;
	col = game_data->player_col;
	map = game_data->map_as_array;
	if (map[row + 1][col] == '1' ||
		(map[row + 1][col] == 'E' && game_data->can_exit == 0))
	{
		return ;
	}
	if (map[row + 1][col] == 'C')
		remove_collectible(game_data, row + 1, col);
	game_data->player_row++;
	game_data->images->player->instances[0].y += PIXELS;
	game_data->moves++;
	ft_printf("Moves: %i\n", game_data->moves);
}

void	move_left(t_game *game_data)
{
	char		**map;
	size_t		row;
	size_t		col;

	row = game_data->player_row;
	col = game_data->player_col;
	map = game_data->map_as_array;
	if (map[row][col - 1] == '1' ||
		(map[row][col - 1] == 'E' && game_data->can_exit == 0))
	{		
		return ;
	}
	if (map[row][col - 1] == 'C')
		remove_collectible(game_data, row, col - 1);
	game_data->player_col--;
	game_data->images->player->instances[0].x -= PIXELS;
	game_data->moves++;
	ft_printf("Moves: %i\n", game_data->moves);
}

void	move_right(t_game *game_data)
{
	char		**map;
	size_t		row;
	size_t		col;

	row = game_data->player_row;
	col = game_data->player_col;
	map = game_data->map_as_array;
	if (map[row][col + 1] == '1' ||
		(map[row][col + 1] == 'E' && game_data->can_exit == 0))
	{
		return ;
	}
	if (map[row][col + 1] == 'C')
		remove_collectible(game_data, row, col + 1);
	game_data->player_col++;
	game_data->images->player->instances[0].x += PIXELS;
	game_data->moves++;
	ft_printf("Moves: %i\n", game_data->moves);
}
