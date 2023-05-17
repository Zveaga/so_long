/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:53:39 by rares         #+#    #+#                 */
/*   Updated: 2023/05/17 20:08:28 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void check()
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_game	*game_data;
	t_image	*image_data;
	
	if (argc != 2)
		raise_error("Program must have 1 argument only!");
	check_extension(argv[1]);
	game_data = initialize_environment(argv[1]);
	game_data->mlx = mlx_init(game_data->width * PIXELS, 
		game_data->height * PIXELS, "so_long", false);
	if (game_data->mlx == NULL)
		return (EXIT_FAILURE);
	image_data = load_images(game_data->mlx);
	game_data->images = image_data;
	fill_space(game_data);
	render_map(game_data);
	mlx_key_hook(game_data->mlx, &move_hook_callback, game_data);
	mlx_loop(game_data->mlx);
	if (game_data->map_as_array[game_data->player_row] 
		[game_data->player_col] == 'E')
		sleep(1);
	mlx_terminate(game_data->mlx);
	ft_free_array(game_data->map_as_array, game_data->height);
	free(game_data);
	free(image_data);
	//atexit(check);
	return (0);
}

// void check(){
// 	system("leaks push_swap");
// }
//atexit(check);

//printf("collected: %zu\n", game_data->collected);
//printf("can_exit: %zu\n", game_data->can_exit);
//printf("moves: %zu\n", game_data->moves);