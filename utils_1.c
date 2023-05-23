/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 14:40:56 by rares         #+#    #+#                 */
/*   Updated: 2023/05/23 18:19:19 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	raise_error(char *str)
{
	write(2, "Error\n", 7);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4
		|| str[len - 4] != '.'
		|| str[len - 3] != 'b'
		|| str[len - 2] != 'e'
		|| str[len - 1] != 'r')
	{
		raise_error("Wrong file extension. File must be in .ber format.");
	}
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
