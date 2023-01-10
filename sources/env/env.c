/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:52:13 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/10 12:10:11 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_addenv(char *name, char *value)
{
	t_env	*new_env;
	int		i;

	new_env = (t_env *)malloc(sizeof(t_env) * (g_minishell->env_size + 1));
	if (!new_env)
		return ;
	i = 0;
	while (i < g_minishell->env_size)
	{
		new_env[i] = g_minishell->env[i];
		i++;
	}
	free(g_minishell->env);
	g_minishell->env = new_env;
	g_minishell->env[g_minishell->env_size].name = ft_strdup(name);
	g_minishell->env[g_minishell->env_size].value = ft_strdup(value);
	g_minishell->env_size++;
}

void	ft_delenv(char *name)
{
	t_env	*new_env;
	int		i;
	int		j;

	new_env = (t_env *)malloc(sizeof(t_env) * (g_minishell->env_size - 1));
	if (!new_env)
		return ;
	i = 0;
	j = 0;
	while (i < g_minishell->env_size)
	{
		if (ft_strcmp(g_minishell->env[i].name, name) != 0)
		{
			new_env[j] = g_minishell->env[i];
			j++;
		}
		i++;
	}
	free(g_minishell->env);
	g_minishell->env = new_env;
	g_minishell->env_size--;
}

void	ft_modenv(char *name, char *new_value)
{
	int	i;

	i = 0;
	while (i < g_minishell->env_size)
	{
		if (ft_strcmp(g_minishell->env[i].name, name) == 0)
		{
			free(g_minishell->env[i].value);
			g_minishell->env[i].value = ft_strdup(new_value);
			return ;
		}
		i++;
	}
	ft_addenv(name, new_value);
}

char	*ft_getenv(char *name)
{
	int	i;

	i = 0;
	while (i < g_minishell->env_size)
	{
		if (ft_strcmp(g_minishell->env[i].name, name) == 0)
			return (g_minishell->env[i].value);
		i++;
	}
	return (NULL);
}

void	ft_initenv(char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	while (env[i])
		i++;
	g_minishell->env = malloc(sizeof(t_env) * i);
	g_minishell->env_size = i;
	i = 0;
	while (env[i])
	{
		tmp = ft_split(env[i], '=');
		g_minishell->env[i].name = ft_strdup(tmp[0]);
		g_minishell->env[i].value = ft_strdup(tmp[1]);
		ft_split_free(tmp);
		i++;
	}
}
