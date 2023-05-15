/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 20:17:02 by rares         #+#    #+#                 */
/*   Updated: 2023/05/10 09:55:24 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_empty_lines(char *str)
{
	int	i;
	
	i = 0;
	if (str == 0)
		raise_error("Map is empty!");
	while(str[i])
	{
		if(str[0] == '\n' || (str[i] == '\n' && str[i + 1] == '\n'))
			raise_error("Map contains empty lines!");		
		i++;
	}
	if(str[i - 1] == '\n')
		raise_error("Map contains empty lines!");		

}

void	check_map_symbols(const char *str)
{
	int	i;
	int	exit;
	int	player;
	int	collectible;
	
	i = 0;
	exit = 0;
	player = 0;
	collectible = 0;
	while (str && str[i])
	{
		if (str[i] == 'E')
			exit++;
		if (str[i] == 'P')
			player++;
		if (str[i] == 'C')
			collectible++;
		if (!ft_strrchr("01CEP\n", str[i]))
			raise_error("Map contains invalid symbols!(1)");
		i++;
	}
	if (exit != 1 || player != 1 || collectible == 0)
		raise_error("Map contains invalid symbols!(2)");
}

void	check_shape(char **map_as_array)
{
	int		i;
	int		width;
	
	i = 0;
	width = ft_strlen(map_as_array[0]);
	while(map_as_array[i])
	{
		if (ft_strlen(map_as_array[i]) != width)
			raise_error("Map must be rectangular!");
		i++;
	}
}

void	check_walls(t_game *game_data)
{
	size_t		row;
	size_t		col;
	char 		**map;

	row = 0;
	col = 0;
	map = game_data->map_as_array;
	while (col < game_data->width)
	{
		if (map[0][col] != '1' || map[game_data->height - 1][col] != '1')
			raise_error("Map must be surrounded by walls!");
		col++;
	}
	while(row < game_data->height)
	{
		if (map[row][0] != '1' || map[row][game_data->width - 1] != '1')
			raise_error("Map must be surrounded by walls!");
		row++;
	}	
}

void	flood_fill(t_game *temp_data, size_t row, size_t col)
{		
	if (temp_data->map_as_array[row][col] == '1')
		return ;
	if (temp_data->map_as_array[row][col] == 'C')
		temp_data->collectibles--;
	if (temp_data->map_as_array[row][col] == 'E')
	{
		temp_data->exit_col = 1;
		return ;
	}
	temp_data->map_as_array[row][col] = '1';
	flood_fill(temp_data, row + 1, col);
	flood_fill(temp_data, row - 1, col);
	flood_fill(temp_data, row, col + 1);
	flood_fill(temp_data, row, col - 1);
}

void	path_checker(t_game *game_data)
{
	t_game		temp_data;
	size_t		i;
	
	temp_data.collectibles = game_data->collectibles;
	temp_data.player_row = game_data->player_row;
	temp_data.player_col = game_data->player_col;
	temp_data.height = game_data->height;
	temp_data.width = game_data->width;
	temp_data.exit_col = 0;
	temp_data.map_as_array = malloc(sizeof(char *) * temp_data.height);
	if (temp_data.map_as_array == NULL)
		raise_error("Failed to allocate memory (temp_data)");
	i = 0;
	while(game_data->map_as_array[i])
	{
		temp_data.map_as_array[i] = ft_strdup(game_data->map_as_array[i]);
		if (temp_data.map_as_array[i] == NULL)
			raise_error("Malloc failed (temp_map_as_array)");
		i++;
	}
	flood_fill(&temp_data, temp_data.player_row, temp_data.player_col);
	if (temp_data.collectibles != 0 || temp_data.exit_col != 1)
		raise_error("Invalid path!");
	ft_free_array(temp_data.map_as_array, temp_data.height);
}
