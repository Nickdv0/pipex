/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:47:18 by nde-vant          #+#    #+#             */
/*   Updated: 2024/03/20 15:44:52 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_handler(int status, char *message)
{
	if (status == 1)
		ft_printf("pipex: invalid number of arguments\n");
	else if (status == 2)
		ft_printf("pipex: %s: No such file or directory\n", message);
	else if (status == 3)
		ft_printf("pipex: %s: Permission denied\n", message);
	else if (status == 4)
		ft_printf("pipex: %s: Error creating file\n", message);
	else if (status == 5)
		ft_printf("pipex: Error waiting for child process\n");
	else if (status == 6)
		ft_printf("pipex: Error creating pipe\n");
	else if (status == 7)
		ft_printf("pipex: Error forking process\n");
	else if (status == 8)
		ft_printf("pipex: Error allocating memory\n");
	else if (status == 9)
		ft_printf("pipex: Error handling pipes\n");
	else if (status == 10)
		ft_printf("pipex: Error opening file\n");
	else if (status == 11)
		ft_printf("pipex: Error command\n");
	exit(status);
}
