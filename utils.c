/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 14:40:56 by rares         #+#    #+#                 */
/*   Updated: 2023/05/18 17:37:42 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void raise_error(char *str)
{
	write(2, "Error\n", 7);
	ft_putendl_fd(str, 2);
	atexit(check);
	exit(EXIT_FAILURE);
}

void	check_extension(char *str)
{
	if (ft_strnstr(str, ".ber", ft_strlen(str)) == NULL)
		raise_error("Wrong file extension. File must be in .ber format.");
}

// void	flush_arrays(t_game *game_data)
// {
// 	if (game_data->map_as_array)
// 		ft_free_array(game_data->map_as_array, game_data->height);
// 	if (game_data)
// 		free(game_data);
// 	if (game_data->images)
// 		free(game_data->images);
// }	

// void raise_error_free(char *str, t_game *game_data)
// {
// 	write(2, "Error\n", 7);
// 	ft_putendl_fd(str, 2);
// 	//flush_arrays(game_data);
// 	atexit(check);

// 	exit(EXIT_FAILURE);
// }