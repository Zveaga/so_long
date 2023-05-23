/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:53:39 by rares         #+#    #+#                 */
/*   Updated: 2023/05/23 18:41:03 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	free_structs_(t_game *game_data, t_image *image_data)
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
	ft_printf("Moves: 0\n");
	mlx_key_hook(game_data->mlx, &move_hook_callback, game_data);
	mlx_loop(game_data->mlx);
	mlx_terminate(game_data->mlx);
	free_structs_(game_data, image_data);
	return (EXIT_SUCCESS);
}

// void	check(void)
// {
// 	system("leaks -q so_long");
// }