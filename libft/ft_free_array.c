/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_array.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 18:38:01 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/02 15:40:20 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_free_array(char **array, size_t rows)
{
	size_t	i;

	i = 0;
	if (array == NULL)
		return ;
	while (i < rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
