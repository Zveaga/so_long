/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:58:47 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/19 17:05:31 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*read_map(char *map)
{
	int		fd;
	char	*line;
	char	*map_as_string;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		raise_error("Failed to open file.");
	map_as_string = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		raise_error("Error while reading the map or map is empty.");
	while (line)
	{
		map_as_string = ft_strjoin(map_as_string, line);
		if (map_as_string == NULL)
			raise_error("Error while reading the map.");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map_as_string);
}
