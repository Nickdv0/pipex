/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:15:33 by nde-vant          #+#    #+#             */
/*   Updated: 2024/03/20 17:25:19 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*free_table(void **table)
{
	int		i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		table[i] = NULL;
		i++;
	}
	free(table);
	return (NULL);
}

// int	file_char_len(int fd)
// {
// 	int		len;
// 	char	buf;

// 	len = 0;
// 	while (read(fd, &buf, 1) > 0)
// 		len++;
// 	return (len);
// }

// char	*get_str(int fd)
// {
// 	char	*str;

// 	str = malloc(sizeof(char) * (file_char_len(fd) + 1));
// 	if (!str)
// 		return (NULL);
// 	read(fd, str, file_char_len(fd));
// 	str[file_char_len(fd)] = 0;
// 	return (str);
// }

// char	**args;

	// close_unused_fds(fd_tab, process, main->argc);
	// pipe_redirect(process, fd_tab, main);
	// args = ft_split(main->argv[process + 2], ' ');
	// if (!args)
	// 	exit_handler(8, NULL);
	// if (process == 0)
	// {
	// 	if (execve(get_command(args[0], main->envp), args, main->envp) == -1)
	// 		exit_handler(11, NULL);
	// 	close(STDIN_FILENO);
	// 	close(STDOUT_FILENO);
	// 	exit(0);
	// }
	// if (process != 0)
	// {
	// 	// char str[5000];
	// 	// read(STDIN_FILENO, str, 5000);
	// 	// str[4999] = 0;
	// 	// ft_printf("process %d data: \n\t%s\n", process, str);
	// 	if (execve(get_command(args[0], main->envp), args, main->envp) == -1)
	// 		exit_handler(11, NULL);
	// 	exit(0);
	// }
	// ft_printf("finished process %d\n", process);
	// exit(0);