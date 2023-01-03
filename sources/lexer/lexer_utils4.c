/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:57:37 by baroun            #+#    #+#             */
/*   Updated: 2023/01/03 17:18:09 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *ft_remove_quotes(char *str)
{
	char	*new;
	int		i;
	int		j;
	
	i = 1;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(str) - 1));
	while (i < (int)ft_strlen(str) - 1)
	{
		new[j] = str[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(str);
	return (new);
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
void	concat_arrow(char **token)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (token[i])
	{
		if (is_arrow(token[i]))
		{
			if (is_arrow(token[i + 1]))
			{
				token[j] = concat_tokens(token[i], token[i + 1]);
				i += 2;
			}
			else
				token[j] = token[i++];
		}
		else
		{
			token[j] = token[i];
			i++;
		}
		j++;
	}
	compact_array(token, j, i);
}
