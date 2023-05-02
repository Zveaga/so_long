/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:53:39 by rares         #+#    #+#                 */
/*   Updated: 2023/05/02 15:58:45 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void check()
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_game	*game;
	
	if (argc != 2)
		raise_error("Program must have 1 argument only!");

	check_extension(argv[1]);
	game = initialize_environment(argv[1]);

	free(game); //FREE
	//atexit(check);
	return (0);
}

// void check(){
// 	system("leaks push_swap");
// }
//atexit(check);