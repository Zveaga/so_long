/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:53:42 by rares         #+#    #+#                 */
/*   Updated: 2023/05/15 11:24:50 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"MLX42/include/MLX42/MLX42.h"
# include"libft/libft.h"
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

# define PIXELS 64

//-------STRUCTS-------//

typedef	struct s_image
{
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*wall;
	mlx_image_t	*space;
	mlx_image_t	*exit_closed;
	mlx_image_t	*exit_open;
}				t_image;

typedef	struct s_game
{
	mlx_t		*mlx;
	char		**map_as_array;
	size_t		height;
	size_t		width;
	size_t		player_row;
	size_t		player_col;
	size_t		exit_row;
	size_t		exit_col;
	size_t		collectibles;
	t_image		*images;
}				t_game;

//-------INITIALIZATION FUNCTIONS-------//
t_game			*initialize_environment(char *str);
t_game 			*initialize_game_parameters(char	**array);
t_image			*load_images(mlx_t *mlx);



//-------IMAGES-------//
void	load_player(mlx_t *mlx, t_image *image);
void	load_collectible(mlx_t *mlx, t_image *image);
void	load_wall(mlx_t *mlx, t_image *image);
void	load_space(mlx_t *mlx, t_image *image);
void	load_exit_closed(mlx_t *mlx, t_image *image);
void	load_exit_open(mlx_t *mlx, t_image *image);


//-------UTILS-------//
void			raise_error(char *str);
void			check_extension(char *str);

//-------MAP-------//
size_t			count_rows(char **map_as_array);
char			*read_map(char *map);
void			check_map_symbols(const char *str);
void			check_shape(char **map_as_array);
void			check_walls(t_game *game_data);
void			check_empty_lines(char *str);
void			get_start_position(t_game *game_data, char c);
void			path_checker(t_game *game_data);
void			get_collectables(t_game *game_data, char *map);

void			render_map(t_game *game_data);
void			fill_space(t_game *game_data);
size_t			get_row(char **map, char c, size_t height, size_t width);
size_t			get_col(char **map, char c, size_t height, size_t width);


#endif