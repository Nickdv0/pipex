/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:46:58 by nde-vant          #+#    #+#             */
/*   Updated: 2024/03/12 11:47:54 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getenv(char *name, char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, name, ft_strlen(name)) == 0)
			return (*envp + ft_strlen(name));
		envp++;
	}
	return (NULL);
}

static char	*get_command_2(char *cmd, char **paths)
{
	int		i;
	char	*command;

	i = -1;
	while (paths[++i])
	{
		command = ft_strjoin(paths[i], cmd);
		if (!command)
			return (NULL);
		if (access(command, F_OK) == 0)
		{
			free_table((void **)paths);
			return (command);
		}
		free(command);
	}
	free_table((void **)paths);
	return (NULL);
}

char	*get_command(char *cmd, char **envp)
{
	char	*path;
	char	**paths;
	char	*command;
	char	*tmp;

	tmp = ft_strjoin("/", cmd);
	path = ft_getenv("PATH=", envp);
	if (!path)
		return (NULL);
	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	command = get_command_2(tmp, paths);
	free(tmp);
	return (command);
}
