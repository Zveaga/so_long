/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_rendering.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 13:34:43 by rares         #+#    #+#                 */
/*   Updated: 2023/05/09 17:22:57 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	render_walls(t_game *game_data)
{
	char		**map;
	size_t		row;
	size_t		col;

	row = 0;
	map = game_data->map_as_array;
	while(row < game_data->height)
	{
		col = 0;
		while(col < game_data->width)
		{
			if (map[row][col] == '1')
				if (mlx_image_to_window(game_data->mlx, game_data->image->wall, 
					PIXELS * col, PIXELS * row) == -1)
					raise_error("Error displaying the wall image.");
		}
	}
}
