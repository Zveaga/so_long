/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 13:33:58 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/04 09:21:37 by rares         ########   odam.nl         */
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
		i++;
	return (i);
}

// int main(void)
// {
// 	char *s = "123456789";
// 	printf("%zu\n", ft_strlen(s));
// }