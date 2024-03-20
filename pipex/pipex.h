/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:28:01 by nde-vant          #+#    #+#             */
/*   Updated: 2024/03/20 17:06:58 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include "ft_printf/include/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <sys/wait.h>

typedef struct s_main
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_main_info;

//utils.c
void	*free_table(void **table);
int		**init_fd_tab(int argc);
// int		file_char_len(char *path);
// char	*get_str(int fd);

//close_fd.c
void	close_unused_fds(int **fd_tab, int process, int argc);
void	close_all(int **fd_tab, int process);

//error.c
int		exit_handler(int error, char *arg);

//command.c
char	*get_command(char *cmd, char **envp);
char	*ft_getenv(char *name, char **envp);

//pipe_redirect.c
void	pipe_redirect(int process, int **fd_tab, t_main_info *main);

#endif