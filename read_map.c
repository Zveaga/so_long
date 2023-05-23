/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:58:47 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/23 13:47:38 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	ft_read_lines(int fd, char **map_as_string, char **line)
{
	free(*line);
	if (*map_as_string == NULL)
	{
		close(fd);
		raise_error("Error while reading the map.");
	}
	*line = get_next_line(fd);
}

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
	{
		close(fd);
		raise_error("Error while reading the map or map is empty.");
	}
	while (line)
	{
		map_as_string = ft_strjoin(map_as_string, line);
		ft_read_lines(fd, &map_as_string, &line);
	}
	close(fd);
	return (map_as_string);
}
