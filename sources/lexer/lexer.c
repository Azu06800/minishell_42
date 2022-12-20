/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:54:34 by baroun            #+#    #+#             */
/*   Updated: 2022/12/21 00:17:21 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_inquote(char	*arg, int j, int *b)
{
	int		in_sq;
	int		in_dq;

	in_sq = 0;
	in_dq = 0;
	if (arg[j] == '\'')
		in_sq = 1;
	if (arg[j] == '"')
		in_dq = 1;
	j++;
	while (arg[j] && (in_sq || in_dq))
	{
		if (arg[j] == '\'')
			in_sq = !in_sq;
		if (arg[j] == '"')
			in_dq = !in_dq;
		j++;
	}
	*b = 0;
	return (j);
}

char	**ft_lexer_boucle(char *arg, char **token, int i, int j)
{
	int	b;
	int	tmp;

	b = 0;
	while (arg[j])
	{
		while (arg[j] && ft_isspace(arg[j]))
			j++;
		tmp = j;
		while (arg[j] && !ft_isspace(arg[j]) && (b || (arg[j + 1] != '"'
					|| arg[i] == '\\')))
		{
			if (arg[j] == '"' && arg[i - 1] != '\\')
				b = !b;
			j++;
		}
		if (b)
			j = ft_inquote(arg, j, &b);
		if ((arg[j] == '"' && arg[i + 1]) || (arg[j + 1] == '"'
				&& arg[i] != '\\'))
			j++;
		token[i++] = ft_substr(arg, tmp, j - tmp);
	}
	return (token);
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

char	**ft_lexer(char *args)
{
	size_t	i;
	char	**token;
	int		j;
	char	*arg;

	i = 0;
	j = 0;
	arg = ft_add_spc(args);
	token = malloc(((cpt_word(arg, j)) + 1) * sizeof(char *));
	token = ft_lexer_boucle(arg, token, i, j);
	token[cpt_word(arg, j)] = NULL;
	free(arg);
	token = ft_lasttoken(token);
	i = 0;
	concat_arrow(token);
	return (token);
}
