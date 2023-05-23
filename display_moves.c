/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_moves.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 17:28:38 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/23 18:45:15 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	display_moves(t_game *game_data)
{
	char	*moves;

	moves = ft_itoa(game_data->moves);
	if (moves == NULL)
		raise_error("Error when converting moves to string.");
	if (game_data->images->moves != NULL)
		mlx_delete_image(game_data->mlx, game_data->images->moves);
	game_data->images->moves = mlx_put_string(game_data->mlx,
			moves, ((2 * PIXELS) + 5),
			((game_data->height - 1) * PIXELS) + 22);
	if (game_data->images->moves == NULL)
		raise_error("Error displaying the moves.");
	free(moves);
}
