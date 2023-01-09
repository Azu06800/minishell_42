/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:25:14 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 16:31:19 by baroun           ###   ########.fr       */
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

int	cmd_exists(t_parser_token *token, t_minishell *minishell)
{
	char	**path;
	char	*cmd;

	path = ft_split(ft_getenv(minishell, "PATH"), ':');
	while (path && *path)
	{
		cmd = ft_strcat(*path, "/");
		cmd = ft_strcat(cmd, token->command[0]);
		if (access(cmd, F_OK) == 0)
		{
			token->command[0] = ft_strdup(cmd);
			free(cmd);
			return (1);
		}
		free(cmd);
		path++;
	}
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
