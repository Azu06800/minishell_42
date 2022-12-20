/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 02:03:06 by baroun            #+#    #+#             */
/*   Updated: 2022/12/21 00:13:58 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */
/* enleve les backslash qui ne sont pas afficher                              */
/* ************************************************************************** */

int	ft_strlenrslash(char *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i] == '\\')
			i++;
		i++;
		j++;
	}
	return (j);
}

char	*ft_remove_bslash(char *arg)
{
	int		i;
	int		j;
	char	*token;

	j = 0;
	i = 0;
	token = malloc((ft_strlenrslash(arg) + 1) * sizeof(char));
	while (arg[i])
	{
		if (arg[i] == '\\')
		{
			i++;
			token[j++] = arg[i++];
			continue ;
		}
		token[j++] = arg[i++];
	}
	token[j] = '\0';
	free(arg);
	return (token);
}

int	is_arrow(char *token)
{
	return (ft_strcmp(token, ">") == 0 || ft_strcmp(token, "<") == 0);
}

char	*concat_tokens(char *token1, char *token2)
{
	return (ft_strjoin(token1, token2));
}

void	compact_array(char **token, int j, int i)
{
	while (j < i)
	{
		token[j] = NULL;
		j++;
	}
}
