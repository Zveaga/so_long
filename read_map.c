/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:58:47 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/04 12:58:20 by rares         ########   odam.nl         */
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
	while(line)
	{
		map_as_string = ft_strjoin(map_as_string, line);
		if (map_as_string == NULL)
			exit(EXIT_FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return(map_as_string);
}