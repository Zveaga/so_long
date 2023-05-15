/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures_1.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 10:32:02 by rares         #+#    #+#                 */
/*   Updated: 2023/05/12 11:34:00 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	load_wall(mlx_t *mlx, t_image *image)
{
	mlx_texture_t *wall;
	
	wall = mlx_load_png("./sprites/wall.png");
	if (wall == NULL)
		raise_error("Problem loading the wall png");
	image->wall = mlx_texture_to_image(mlx, wall);
	if(image->wall == NULL)
		raise_error("Problem creating the wall image");
	mlx_delete_texture(wall);
}

void	load_space(mlx_t *mlx, t_image *image)
{
	mlx_texture_t *space;
	
	space = mlx_load_png("./sprites/space.png");
	if (space == NULL)
		raise_error("Problem loading the space png");
	image->space = mlx_texture_to_image(mlx, space);
	if(image->space == NULL)
		raise_error("Problem creating the space image");
	mlx_delete_texture(space);
}

void	load_exit_closed(mlx_t *mlx, t_image *image)
{
	mlx_texture_t *exit_closed;
	
	exit_closed = mlx_load_png("./sprites/exit_closed.png");
	if (exit_closed == NULL)
		raise_error("Problem loading the exit_closed png");
	image->exit_closed = mlx_texture_to_image(mlx, exit_closed);
	if(image->exit_closed == NULL)
		raise_error("Problem creating the exit_closed image");
	mlx_delete_texture(exit_closed);
}

void	load_exit_open(mlx_t *mlx, t_image *image)
{
	mlx_texture_t *exit_open;
	
	exit_open = mlx_load_png("./sprites/exit_open.png");
	if (exit_open == NULL)
		raise_error("Problem loading the exit_open png");
	image->exit_open = mlx_texture_to_image(mlx, exit_open);
	if(image->exit_open == NULL)
		raise_error("Problem creating the exit_open image");
	mlx_delete_texture(exit_open);
}
