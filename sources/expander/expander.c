/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:29:07 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 16:58:09 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	ft_isalnum(char str)
{
	if (ft_isalpha(str) || ft_isdigit(str))
		return (1);
	return (0);
}

char *expand_variable(t_minishell *minishell, char *string)
{
	size_t buffer_size = ft_strlen(string) + 1;
	char *buffer = malloc(buffer_size);
	if (!buffer)
	{
		perror("malloc");
		exit(1);
	}
	char *ptr = buffer;
	while (*string)
	{
		if (*string == '$')
		{
			string++;
			char *var_start = string;
			while (ft_isalnum(*string) || *string == '_')
				string++;
			char *var_name = ft_strndup(var_start, string - var_start);
			char *var_value = ft_getenv(minishell, var_name);
			if (var_value)
			{
				size_t value_length = ft_strlen(var_value);
				if (ptr - buffer + value_length >= buffer_size)
				{
					size_t old_size = buffer_size;
					buffer_size += value_length;
					buffer = ft_realloc(buffer, buffer_size);
					if (!buffer)
					{
						perror("realloc");
						exit(1);
					}
					ptr = buffer + old_size - 1;
				}
				ft_strcpy(ptr, var_value);
				ptr += value_length;
			}
			free(var_name);
		}
		else
			*ptr++ = *string++;
	}
	*ptr = '\0';

	return buffer;
}

void	expand_variables(t_minishell *minishell, char **strings, size_t size)
{
	size_t	i;
	char	*current;
	char	*expanded;

	i = -1;
	while (++i < size)
	{
		current = strings[i];
		expanded = expand_variable(minishell, current);
		free(current);
		strings[i] = expanded;
	}
}

void	ft_expander(t_parser_token *tokens, t_minishell *minishell)
{
	int	i;

	i = -1;
	while (tokens[++i].type != TOKEN_END)
	{
		if (tokens[i].type == TOKEN_CMD)
		{
			// Expand variables in the command
			expand_variables(minishell, tokens[i].command, tokens[i].command_size);
		}
	}
}
