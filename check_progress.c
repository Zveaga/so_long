/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_progress.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 17:25:57 by rares         #+#    #+#                 */
/*   Updated: 2023/05/18 12:46:04 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_progress(t_game *game_data)
{
	char	**map;

	map = game_data->map_as_array;
	if (game_data->collected == game_data->collectibles)
		game_data->can_exit = 1;
	if (map[game_data->player_row][game_data->player_col] == 'E')
	{
		ft_printf("You won!\n");
		mlx_close_window(game_data->mlx);
	}
}

