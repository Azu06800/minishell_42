/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:49:15 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 00:17:31 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int        at_least_one_cmd(t_parser_token *tokens)
{
    int        i;

    i = 0;
    while (tokens[i].type != TOKEN_END)
    {
        if (tokens[i].type == TOKEN_CMD)
            return (1);
        i++;
    }
    return (0);
}

int        token_cmd_after_redir(t_parser_token *tokens)
{
    int        i;

    i = 0;
    while (tokens[i].type != TOKEN_END)
    {
        if (tokens[i].type == TOKEN_REDIR)
        {
            if (tokens[i + 1].type != TOKEN_CMD)
                return (0);
        }
        i++;
    }
    return (1);
}

t_parser_token        *no_consecutive_redir(t_parser_token *tokens)
{
    int        i;

    i = 0;
    while (tokens[i].type != TOKEN_END)
    {
        if (tokens[i].type == TOKEN_REDIR)
        {
            if (tokens[i + 1].type == TOKEN_REDIR)
                return (&tokens[i + 1]);
        }
        i++;
    }
    return (NULL);
}

int        ft_validator(t_parser_token *tokens)
{
    t_parser_token  *error;
    if (!at_least_one_cmd(tokens))
        return (0);
    error = no_consecutive_redir(tokens);
    if (error != NULL)
    {
        ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
        ft_putstr_fd(redir_type_to_str(tokens), 2);
        ft_putstr_fd("'\n", 2);
        return (0);
    }
    if (!token_cmd_after_redir(tokens))
    {
        ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
        return (0);
    }
    return (1);
}