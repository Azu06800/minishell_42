/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:52:56 by baroun            #+#    #+#             */
/*   Updated: 2023/01/03 19:02:46 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int    ft_strlenspcqu(char *arg)
{
    int i;
    int    j;

    i = 0;
    j = 0;
    while(arg[i])
    {
        if (ft_isquote(arg[i]))
            j++;
        i++;
    }
    return (i + j);
}

char    *ft_add_spcqu(char *arg)
{
    int in_q;
    char *new;
    int i;
    int j;

    i = 0;
    j = 0;
    in_q = 0;
    new = malloc(sizeof(char) * ft_strlenspcqu(arg) + 1);
    while(arg[i])
    {
        if (!in_q && ft_isquote(arg[i]))
        {
            in_q = !in_q;
            new[j++] = ' ';
        }
        new[j++] = arg[i++];
        if (in_q && ft_isquote(arg[i]))
        {
            in_q = !in_q;
            new[j++] = arg[i++];
            new[j++] = ' ';
        }
    }
    new[j] = '\0';
	free(arg);
	return(new);
}


/* ************************************************************************** */
/* enlever espace en trop			                                          */
/* ************************************************************************** */

int    ft_strlenrmspc(char *arg)
{
	int i;

	i = 0;
	while (!ft_isspace(arg[i]))
		i++;
	return(i);
}

char	*ft_rmspc(char *arg)
{
	int i;
	int j;
	char *new;

    i = 0;
    j = 0;
    new = malloc(sizeof(char) * ft_strlenrmspc(arg) + 1);
    while (!ft_isspace(arg[i]))
        new[j++] = arg[i++];
    new[j] = '\0';
    free(arg);
    return(new);
}
