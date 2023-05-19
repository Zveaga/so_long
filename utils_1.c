/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 14:40:56 by rares         #+#    #+#                 */
/*   Updated: 2023/05/19 19:35:13 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	raise_error(char *str)
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

void	check_shape(char **map_as_array)
{
	int		i;
	int		width;

	i = 0;
	width = ft_strlen(map_as_array[0]);
	while (map_as_array && map_as_array[i])
	{
		if (ft_strlen(map_as_array[i]) != width)
			raise_error("Map must be rectangular!");
		i++;
	}
}
