/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_moves.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 17:28:38 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/18 20:14:54 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	display_moves(t_game *game_data)
{
	static char *moves;
	
	moves = ft_itoa(game_data->moves);
	if (moves == NULL)
		raise_error("Error when converting moves to string.");
	if (mlx_put_string(game_data->mlx, moves, (2 * PIXELS), 
		((game_data->height - 1) * PIXELS) + 22) == NULL)
	{
		raise_error("Error displaying the moves.");
	}
	free(moves);
}