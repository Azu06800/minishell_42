/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:54:34 by baroun            #+#    #+#             */
/*   Updated: 2022/11/23 16:20:33 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char  *ft_strcpy(char c)
{
  char *d;
  
  d = malloc(sizeof(char) * 2);
  d[0] = c;
  d[1] = '\0';

  return (d);
}

char    **ft_lexer(char *arg)
{
    size_t        len;
    size_t        i;
    int            tmp;
    char        **token;
    int            j;

    i = 0;
    j = 0;
    token = (char **)malloc(((cpt_word(arg)) + 1) * sizeof(char *));
    while (arg[j])
    {
        while (arg[j] && ft_isspace(arg[j]))
            j++;
        len = 0;
        tmp = j;
        while (arg[j] && !ft_isspace(arg[j]) && (int)len++ != -1)
        {   
			if (ft_issep(arg[j]))
			{
				len = 0;
            	token[i++] = ft_strcpy(arg[j]);
			}
            j++;
        }
        if (!ft_isspace(arg[j - 1]))
            token[i++] = ft_substr(arg + tmp, 0, len);
    }
    return (token);
}
