/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:52:13 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/01 22:25:53 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_addenv(t_minishell *minishell, char *name, char *value)
{
	t_env	*new_env;
	int		i;

	new_env = (t_env *)malloc(sizeof(t_env) * (minishell->env_size + 1));
	i = 0;
	while (i < minishell->env_size)
	{
		new_env[i] = minishell->env[i];
		i++;
	}
	free(minishell->env);
	minishell->env = new_env;
	minishell->env[minishell->env_size].name = name;
	minishell->env[minishell->env_size].value = value;
	minishell->env_size++;
}

void	ft_delenv(t_minishell *minishell, char *name)
{
	t_env	*new_env;
	int		i;
	int		j;

	new_env = (t_env *)malloc(sizeof(t_env) * (minishell->env_size - 1));
	i = 0;
	j = 0;
	while (i < minishell->env_size)
	{
		if (ft_strcmp(minishell->env[i].name, name) != 0)
		{
			new_env[j] = minishell->env[i];
			j++;
		}
		i++;
	}
	free(minishell->env);
	minishell->env = new_env;
	minishell->env_size--;
}

void	ft_modenv(t_minishell *minishell, char *name, char *new_value)
{
	int	i;

	i = 0;
	while (i < minishell->env_size)
	{
		if (ft_strcmp(minishell->env[i].name, name) == 0)
		{
			free(minishell->env[i].value);
			minishell->env[i].value = new_value;
			return ;
		}
		i++;
	}
	ft_addenv(minishell, name, new_value);
}

char	*ft_getenv(t_minishell *minishell, char *name)
{
	int	i;

	i = 0;
	while (i < minishell->env_size)
	{
		if (ft_strcmp(minishell->env[i].name, name) == 0)
			return (minishell->env[i].value);
		i++;
	}
	return (NULL);
}

void	ft_initenv(t_minishell *minishell, char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	while (env[i])
		i++;
	minishell->env = malloc(sizeof(t_env) * i);
	minishell->env_size = i;
	i = 0;
	while (env[i])
	{
		tmp = ft_split(env[i], '=');
		minishell->env[i].name = tmp[0];
		minishell->env[i].value = tmp[1];
		free(tmp);
		i++;
	}
}
