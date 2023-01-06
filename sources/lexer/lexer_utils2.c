/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:36:41 by baroun            #+#    #+#             */
/*   Updated: 2023/01/06 16:36:43 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\f' || c == '\r');
}

int	ft_isword(char *str, int i)
{
	return ((str[i] > 32 && str[i] < 127) \
	&& (ft_isspace(str[i + 1] || str[i + 1] == '\0')));
}

int	ft_issep(int c)
{
	return (ft_isfle(c) || ft_isquote(c));
}

int	ft_isquote(int c)
{
	return (c == '\"' || c == '\'');
}

int	ft_isfle(int c)
{
	return (c == '>' || c == '<' || c == '|');
}
