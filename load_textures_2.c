/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures_2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 10:32:02 by rares         #+#    #+#                 */
/*   Updated: 2023/05/18 17:19:53 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	load_player(mlx_t *mlx, t_image *image)
{
	mlx_texture_t *player;
	
	player = mlx_load_png("./textures/player.png");
	if (player == NULL)
		raise_error("Problem loading the player png");
	image->player = mlx_texture_to_image(mlx, player);
	if(image->player == NULL)
		raise_error("Problem creating the player image");
	mlx_delete_texture(player);
}

void	load_collectible(mlx_t *mlx, t_image *image)
{
	mlx_texture_t *collectible;
	
	collectible = mlx_load_png("./textures/collectible.png");
	if (collectible == NULL)
		raise_error("Problem loading the collectible png");
	image->collectibles = mlx_texture_to_image(mlx, collectible);
	if(image->collectibles == NULL)
		raise_error("Problem creating the collectible image");
	mlx_delete_texture(collectible);
}
