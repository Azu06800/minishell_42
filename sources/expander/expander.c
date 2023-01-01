/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:29:07 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/01 23:42:56 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;

	copy = malloc(n + 1);
	if (copy == NULL)
		return (NULL);
	copy[n] = '\0';
	return ((char *)ft_memcpy(copy, s1, n));
}

static void	ft_expander_dollar(t_parser_token *token, t_minishell *minishell,
	int i)
{
	int		j;
	char	*name;
	char	*value;
	char	*temp;

	j = 1;
	while (token->command[i][j] && ft_isalnum(token->command[i][j]))
		j++;
	name = ft_strndup(token->command[i] + 1, j - 1);
	value = ft_getenv(minishell, name);
	if (value)
	{
		temp = ft_strjoin(value, token->command[i] + j);
		free(token->command[i]);
		token->command[i] = temp;
	}
	free(name);
}

void	ft_expander(t_parser_token *token, t_minishell *minishell)
{
	int	i;

	i = 0;
	while (token->command[i])
	{
		if (ft_strchr(token->command[i], '$'))
			ft_expander_dollar(token, minishell, i);
		i++;
	}
}
