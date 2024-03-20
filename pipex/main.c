/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:24:37 by nde-vant          #+#    #+#             */
/*   Updated: 2024/03/20 17:26:53 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	valid_input(char **argv, int argc)
{
	int	fd;

	if (argc < 5)
		return (exit_handler(1, NULL));
	if (access(argv[1], F_OK) == -1)
		return (exit_handler(2, argv[1]));
	if (access(argv[1], R_OK) == -1 || access(argv[1], W_OK) == -1)
		return (exit_handler(3, argv[1]));
	if (access(argv[argc - 1], F_OK) == -1)
	{
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			return (exit_handler(4, argv[argc - 1]));
		close(fd);
	}
	if (access(argv[argc - 1], W_OK) == -1
		|| access(argv[argc - 1], F_OK) == -1)
		return (exit_handler(3, argv[argc - 1]));
	return (0);
}

void	()

void	forking_process(int **fd_tab, t_main_info *main)
{
	int	id;

	id = fork();
	if (id == 0)
		
}

int	main(int argc, char **argv, char **envp)
{
	int			**fd_tab;
	t_main_info	main;

	main.argc = argc;
	main.argv = argv;
	main.envp = envp;
	valid_input(argv, argc);
	fd_tab = init_fd_tab(argc);
	if (!fd_tab)
		return (exit_handler(6, NULL));
	forking_process(fd_tab, &main);
	return (1);
}

//TODO: make child wait for other child to finish before executing