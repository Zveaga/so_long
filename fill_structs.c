/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_structs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/29 13:52:11 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/15 16:58:56 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

t_game *initialize_game_parameters(char	**array)
{
	t_game	*game_data;

	game_data = malloc(sizeof(t_game));
	if (game_data == NULL)
		raise_error("Failed to allocate memmory for the game struct.");
	game_data->map_as_array = array;
	game_data->height = count_rows(array);
	game_data->width = ft_strlen(array[0]);
	game_data->collected = 0;
	game_data->can_exit = 0;

	get_start_position(game_data, 'P');
	get_start_position(game_data, 'E');
	return (game_data);
}

t_game	*initialize_environment(char *str)
{
	t_game	*game_data;
	char	*map_as_string;
	char	**map_as_array;

	map_as_string = read_map(str);
	
	check_empty_lines(map_as_string);
	map_as_array = 	ft_split(map_as_string, '\n');
	if (map_as_array == NULL)
		raise_error("map_as_array returned NULL.");
	check_map_symbols(map_as_string);
	check_shape(map_as_array);
	game_data = initialize_game_parameters(map_as_array);
	check_walls(game_data);
	get_collectables(game_data, map_as_string);
	path_checker(game_data);

	//printf("%zu\n", game_data->height);
	//printf("\n%zu\n", game_data->collectibles);

	printf("%s\n", map_as_string);
	free(map_as_string);
	//ft_free_array(map_as_array, game_data->height); // -> might need it
	return(game_data);
}

t_image	*load_images(mlx_t *mlx)
{
	t_image	*image_data;
	
	image_data = malloc(sizeof(t_image));
	if (image_data == NULL)
		raise_error("Failed to allocate memmory for image_data struct.");
	load_player(mlx, image_data);
	load_collectible(mlx, image_data);
	load_wall(mlx, image_data);
	load_space(mlx, image_data);
	load_exit_closed(mlx, image_data);
	return (image_data);
}

	// printf("player_col: %zu\n", game_data->player_col);
	// printf("player_row: %zu\n", game_data->player_row);
	// printf("exit_col: %zu\n", game_data->exit_col);
	// printf("exit_row: %zu\n", game_data->exit_row);