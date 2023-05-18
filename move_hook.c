/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_hook.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 12:24:29 by rares         #+#    #+#                 */
/*   Updated: 2023/05/18 20:01:01 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	move_hook_callback(mlx_key_data_t keydata, void *data)
{
	t_game	*game_data;
	
	game_data = (t_game *)data;
	check_progress(game_data);
	display_moves(game_data);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game_data->mlx);
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS))
		move_up(game_data);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS))
		move_down(game_data);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS))
		move_left(game_data);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS))
		move_right(game_data);
}