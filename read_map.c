/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:58:47 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/28 20:33:45 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int	len_line(char *reserve)
{
	int	i;

	i = 0;
	while (reserve[i] != '\n' && reserve[i])
		i++;
	if (reserve[i] == '\n')
		i++;
	return (i);
}

static char	*update_reserve(char *reserve)
{
	char	*dup;
	int		i;
	int		j;

	i = len_line(reserve);
	if (reserve[i] == '\0')
	{
		free(reserve);
		return (NULL);
	}
	dup = malloc(sizeof(char) * (ft_strlen(reserve) - i + 1));
	if (dup == NULL)
	{
		free(reserve);
		reserve = NULL;
		return (NULL);
	}
	j = 0;
	while (reserve[i])
	{
		dup[j] = reserve[i];
		j++;
		i++;
	}
	dup[j] = '\0';
	free(reserve);
	return (dup);
}

static char	*save_line(char *reserve)
{
	int		i;
	char	*dup;
	int		flag;

	i = len_line(reserve);
	dup = malloc(sizeof(char) * (i + 1));
	i = 0;
	flag = 0;
	if (dup == NULL)
		return (NULL);
	while (reserve && reserve[i] && (flag == 0))
	{
		dup[i] = reserve[i];
		if (reserve[i] == '\n')
			flag = 1;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	*read_and_reserve(char *reserve, int fd)
{	
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		free(reserve);
		return (NULL);
	}
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(reserve), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		reserve = ft_strjoin(reserve, buffer);
		if (reserve == NULL || ft_strchr(reserve, '\n') != 0)
			break ;
	}
	free(buffer);
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char		*reserve;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reserve = read_and_reserve(reserve, fd);
	if (reserve == NULL)
		return (NULL);
	line = save_line(reserve);
	if (line == NULL)
	{
		if (reserve)
		{
			free(reserve);
			reserve = NULL;
		}
		return (NULL);
	}
	reserve = update_reserve(reserve);
	return (line);
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