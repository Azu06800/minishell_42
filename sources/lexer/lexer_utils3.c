/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:19:43 by baroun            #+#    #+#             */
/*   Updated: 2022/12/07 17:26:43 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//gerer > et <
int	ft_strlenspc(char *arg)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while(arg[++i])
	{
		if (ft_isfle(arg[i]))
			j += 2;
	}
	return (i + j);
}

char    *ft_add_spc(char *arg)
{
    char	*r;
    int		i;
    int		j;

    i = 0;
    j = 0;
    r = malloc((ft_strlenspc(arg)) * sizeof(char));
    while (arg[i])
    {
        if (ft_isfle(arg[i]))
        {
            r[j++] = ' ';
            r[j++] = arg[i++];
            r[j++] = ' ';
        }
        r[j++] = arg[i++];
    }
	r[j] = '\0';
    return (r);
}

int	ft_strlenrspc(char *arg)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while(arg[++i])
	{
		if (ft_isfle(arg[i]))
			j -= 2;	
	}
	return (i + j);
}

char    *ft_remove_spc(char *arg)
{
    int     i;
    int     j;
    char    *token;

    i = 0;
    j = 0;
    token = malloc((ft_strlenrspc(arg)) * sizeof(char));
    while (arg[i])
    {
        if (ft_isspace(arg[i]) && ft_isfle(arg[i + 1]))
        {
            token[j++] = arg[i + 1];
            i += 3;
        }
        token[j++] = arg[i++];
    }
    token[j] = '\0';
    return (token);
}

char    **ft_lasttoken(char **token)
{
    int     i;

    i = -1;
    while (token[++i])
    {
        if (ft_isquote(token[i][0]))
            token[i] = ft_remove_spc(token[i]);
    }
    return (token);
}
