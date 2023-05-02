/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/29 14:38:19 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/02 11:49:20 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

size_t	count_rows(char **map_as_array)
{
	int	i;

	i = 0;
	while(map_as_array[i])
		i++;
	return (i);
}

size_t	get_row(char **map, char c, size_t height, size_t width)
{
	size_t		row;
	size_t		col;
	
	row = 0;
	while(row < height)
	{
		col = 0;
		while(col < width)
		{

			if(map[row][col] == c)
				break ;
			col++;
		}
		if(map[row][col] == c)
				break ;
		row++;
	}
	return(row);
}

size_t	get_col(char **map, char c, size_t height, size_t width)
{
	size_t		row;
	size_t		col;
	
	row = 0;
	while(row < height)
	{
		col = 0;
		while(col < width)
		{

			if(map[row][col] == c)
				break ;
			col++;
		}
		if(map[row][col] == c)
				break ;
		row++;
	}
	return(col);
}

void	get_start_position(t_game *game_data, char c)
{
	size_t		height;
	size_t		width;
	char		**map;

	map = game_data->map_as_array;
	height = game_data->height;
	width = game_data->width;
	
	if (c == 'P')
	{
		game_data->player_row = get_row(map, c, height, width);
		game_data->player_col = get_col(map, c, height, width);
	}
	if (c == 'E')
	{
		game_data->exit_row = get_row(map, c, height, width);
		game_data->exit_col = get_col(map, c, height, width);
	}
}

void	get_collectables(t_game *game_data, char *map)
{
	int		i;
	size_t	collectibles;
	
	
	i = 0;
	collectibles = 0;
	while(map[i])
	{
		if (map[i] == 'C')
			collectibles++;
		i++;
	}
	game_data->collectibles = collectibles;
}
