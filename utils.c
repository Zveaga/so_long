/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 14:40:56 by rares         #+#    #+#                 */
/*   Updated: 2023/04/28 19:23:19 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void raise_error(char *str)
{
	write(2, "Error\n", 7);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	check_extension(char *str)
{
	if (ft_strnstr(str, ".ber", ft_strlen(str)) == NULL)
		raise_error("Wrong file extension. File must be in .ber format.");
}