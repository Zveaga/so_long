/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:53:39 by rares         #+#    #+#                 */
/*   Updated: 2023/05/09 17:21:40 by rares         ########   odam.nl         */
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
	
	if (argc != 2)
		raise_error("Program must have 1 argument only!");

	check_extension(argv[1]);
	game_data = initialize_environment(argv[1]);
	game_data->mlx = mlx_init(game_data->width * PIXELS, 
		game_data->height * PIXELS, "so_long", false);
	if (game_data->mlx == NULL)
		return (EXIT_FAILURE);

	render_walls(game_data);
	mlx_loop(game_data->mlx);\
	mlx_terminate(game_data->mlx);
	//free(game); //FREE
	//atexit(check);
	return (0);
}

// void check(){
// 	system("leaks push_swap");
// }
//atexit(check);