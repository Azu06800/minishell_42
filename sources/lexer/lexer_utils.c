/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:00:21 by baroun            #+#    #+#             */
/*   Updated: 2023/01/07 07:37:18 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int    ft_cptquote(char *args, int *i)
{
    char quote;

    quote = args[(*i)++];
    while (args[*i] && args[*i] != quote)
        (*i)++;
    return (1);
}

int ft_cptarg(char *args, int *i)
{
    while (args[*i] && !ft_isspace(args[*i]) && !ft_issep(args[*i]))
        (*i)++;
    (*i)--;
    return (1);
}

int ft_cptarrow(char *args, int *i)
{
    if (args[*i] == args[*i + 1])
        (*i)++;
    return (1);
}

size_t    ft_cptword(char *args)
{
    int i;
    int j;

    i = -1;
    j = 0;
    while(args[++i])
    {
        if (ft_isquote(args[i]))
        {
            j += ft_cptquote(args, &i);
            continue;
        }
        else if (ft_isfle(args[i]))
        {
            j += ft_cptarrow(args, &i);
            continue;
        }
        else if (ft_isspace(args[i]))
            continue;
        else
            j += ft_cptarg(args, &i);
    }
    return (j + 1);
}
