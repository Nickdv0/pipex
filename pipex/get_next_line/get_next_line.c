/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:13:14 by nde-vant          #+#    #+#             */
/*   Updated: 2024/03/19 16:19:04 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_next_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*free_str(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	*long_str_return(char *str, char *stocker, int is_mem_all)
{
	char	*tmp_str;
	int		len;

	len = len_next_line(str) + 1;
	tmp_str = ft_substr_gnl(str, 0, len);
	if (!tmp_str)
		return (NULL);
	ft_strlcpy_gnl(stocker, str + len, ft_strlen_gnl(str + len) + 1);
	if (is_mem_all)
	{
		free_str(str);
	}
	return (tmp_str);
}

char	*alt_str_return(char *stocker, int fd, int *check)
{
	char	*str;

	str = ft_substr_gnl(stocker, 0, ft_strlen_gnl(stocker));
	if (!str)
		return (NULL);
	while (*check)
	{
		ft_memset_gnl(stocker, 0, BUFFER_SIZE + 1);
		*check = (int)read(fd, stocker, BUFFER_SIZE);
		if (*check == -1)
			return (free_str(str));
		str = ft_strjoin_gnl(str, stocker);
		if (*check < 1)
		{
			if (ft_strlen_gnl(str))
				return (str);
			return (free_str(str));
		}
		if (len_next_line(str) > -1)
			return (long_str_return(str, stocker, 1));
	}
	return (long_str_return(str, stocker, 0));
}

char	*get_next_line(int fd)
{
	int				check;
	static char		stocker[BUFFER_SIZE + 1] = {0};

	check = 1;
	if (len_next_line(stocker) > -1)
	{
		return (long_str_return(stocker, stocker, 0));
	}
	return (alt_str_return(stocker, fd, &check));
}
//#include <stdio.h>
//
//int main(void)
//{
//	int fd = open("test.txt", O_RDONLY);
//	/*char str[100] = "lorem\nipsum\n";*/
//
////	printf("%s", long_str_return(str, str));
////	printf("%s", alt_str_return(str, fd));
////	printf("%s", str);
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//}