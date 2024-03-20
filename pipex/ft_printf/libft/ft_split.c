/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:11:34 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/12 10:11:57 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] && s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static int	*arr_free(char **table, int tb_size)
{
	int	i;

	i = 0;
	while (i < tb_size)
	{
		if (table[i])
		{
			free(table[i]);
			table[i] = NULL;
		}
		i++;
	}
	free(table);
	table = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		str_num;
	char	**str_arr;
	int		i;
	int		j;

	i = 0;
	j = -1;
	str_num = word_counter(s, c);
	str_arr = (char **)malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			str_arr[++j] = ft_substr(s, i, word_len(s + i, c));
			if (!str_arr[j])
				return ((char **)arr_free(str_arr, j));
			i += word_len(s + i, c);
		}
		else
			i++;
	}
	str_arr[str_num] = 0;
	return (str_arr);
}
