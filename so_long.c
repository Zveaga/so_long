/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:53:39 by rares         #+#    #+#                 */
/*   Updated: 2023/05/19 19:40:25 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check(void)
{
	system("leaks -q so_long");
}

static void	free_structs(t_game *game_data, t_image *image_data)
{
	ft_free_array(game_data->map_as_array, game_data->height);
	free(game_data);
	free(image_data);
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
		raise_error("Error while initializing the mlx handle.");
	image_data = load_images(game_data->mlx);
	game_data->images = image_data;
	render_map(game_data);
	mlx_key_hook(game_data->mlx, &move_hook_callback, game_data);
	mlx_loop(game_data->mlx);
	if (game_data->map_as_array[game_data->player_row]
		[game_data->player_col] == 'E')
		sleep(1);
	mlx_terminate(game_data->mlx);
	free_structs(game_data, image_data);
	atexit(check);
	return (EXIT_SUCCESS);
}
