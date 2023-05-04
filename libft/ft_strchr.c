/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 17:57:20 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/04 09:21:07 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *str, int c)
{	
	while (str && *str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}

// int	main(void)
// {
// 	char	*str = "bbaAbbbbabb";

// 	printf("Own:  %s\n", ft_strchr(str, 'A'));
// 	printf("Real: %s\n", strchr(str, 'A'));
// }