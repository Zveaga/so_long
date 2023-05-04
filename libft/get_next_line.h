/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 13:38:48 by raanghel      #+#    #+#                 */
/*   Updated: 2023/05/04 12:57:16 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include"libft.h"
# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>
# include<stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

char	*get_next_line(int fd);

int		len_line(char *reserve);

#endif