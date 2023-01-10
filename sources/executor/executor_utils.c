/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:25:14 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/10 13:24:18 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	cmd_exists(t_parser_token *token)
{
	char	**path;
	char	*full_path;

	if (token->command[0][0] == '/' || token->command[0][0] == '.')
		return (1);
	if (ft_getenv("PATH") != NULL)
		path = ft_split(ft_getenv("PATH"), ':');
	else
		return (0);

	while (path && *path)
	{
		full_path = ft_strjoin(*path, "/");
		full_path = ft_strjoin(full_path, token->command[0]);
		if (access(full_path, X_OK) == 0)
		{
			if (ft_strlen(token->command[0]) > 0)
			{
				token->command[0] = ft_strdup(full_path);
				free(full_path);
				return (1);
			}
		}
		free(full_path);
		path++;
	}
	ft_split_free(path);
	return (0);
}

static char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

static int	count_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*dst;
	int			count;
	int			i;
	long int	num;

	num = n;
	count = count_size(num);
	i = 0;
	if (num < 0 || count == 0)
		count++;
	dst = ft_strnew(count);
	if (dst == NULL)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		dst[0] = '-';
		i++;
	}
	while (count-- > i)
	{
		dst[count] = (num % 10) + '0';
		num /= 10;
	}
	return (dst);
}
