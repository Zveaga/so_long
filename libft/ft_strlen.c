/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 13:33:58 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/28 16:15:16 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	char *s = "123456789";
// 	printf("%zu\n", ft_strlen(s));
// }