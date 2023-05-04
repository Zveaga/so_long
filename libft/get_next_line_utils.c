/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/12 17:17:16 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/04 09:22:05 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	len_line(char *reserve)
{
	int	i;

	i = 0;
	while (reserve[i] != '\n' && reserve[i])
		i++;
	if (reserve[i] == '\n')
		i++;
	return (i);
}
