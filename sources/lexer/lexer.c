/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:59:39 by baroun            #+#    #+#             */
/*   Updated: 2023/01/06 16:34:45 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_sepcpy(char *arg, t_parser_token tokens, int *i)
{
	char	*d;
	int		j;

	j = 2;
	if (arg[*i] == arg[*i + 1])
		j++;
	d = malloc(sizeof(char) * 2);
	d[0] = arg[*i];
	d[1] = arg[*i + 1];
	if (arg[*i] == arg[*i + 1])
	{
		d[2] = '\0';
		(*i)++;
	}
	else
		d[1] = '\0';
}

char *ft_argcpy(char *args, int *i, t_parser_token tokens)
{
    char    *arg;
    int        j;

    j = *i;
	tokens.spcecho = 1;
	if (ft_isquote(args[*i - 1]))
		tokens.spcecho = 0;
    while (args[j] && !ft_issep(args[j]) && !ft_isspace(args[j]))
        j++;
    arg = malloc(sizeof(char) * j - *i + 1);
    j = 0;
    while (args[*i] && !ft_isspace(args[*i]) && !ft_issep(args[*i]))
        arg[j++] = args[(*i)++];
    arg[j] = '\0';
	(*i)--;
    tokens.command = arg;
}

void	ft_quotecpy(char *args, int *i, t_parser_token tokens)
{
    char    *new;
    int        j;
    char    quote;

    j = *i;
	tokens.spcecho = 1;
	if (ft_isquote(args[*i - 1]))
		tokens.spcecho = 0;
    quote = args[(*i)++];
    while (args[j] && args[j] != quote)
        j++;
    new = malloc(sizeof(char) * j - *i + 3);
    j = 0;
    new[j++] = args[(*i) - 1];
    while (args[*i] && args[(*i)] != quote)
        new[j++] = args[(*i)++];
    new[j++] = args[(*i)];
    new[j] = '\0';
    tokens.command = new;
}

t_parser_token	*ft_lexer(char *args)
{
	t_parser_token	*tokens;
	int			i;
	int			j;

	i = -1;
	j = 0;
	tokens = malloc(sizeof(t_parser_token) * ft_cptword(args));
	while(args[++i])
	{
		printf("c = %c ,i = %d\n", args[i], i);
		if (ft_isquote(args[i]))
		{
			ft_quotecpy(args, &i, tokens[j++]);
			continue;
		}
		else if (ft_isfle(args[i]))
		{
			ft_sepcpy(args[i], tokens[j], &i);
			continue;
		}
		else if (ft_isspace(args[i]))
			continue;
		else
			ft_argcpy(args, &i, tokens[j]);
	}
	tokens[j].command = NULL;
	return (tokens);
}
