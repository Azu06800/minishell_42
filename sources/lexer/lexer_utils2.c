/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:48:34 by baroun            #+#    #+#             */
/*   Updated: 2022/11/25 20:17:59 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\f' || c == '\r');
}

int ft_isword(char *str, int i)
{
	return ((str[i] > 32 && str[i] < 127) && (ft_isspace(str[i + 1] || str[i + 1] == '\0')));
}

int ft_issep(int c)
{
	return(c == '>'|| c == '<');
}

int	ft_isquote(int c)
{
	return(c == '\"' || c == '\'');
}

size_t	cpt_quote(char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while(s[i])
	{
		if (ft_isquote(s[i]))
			j++;
		i++;
	}
	return ((j / 2 * 3));
}
