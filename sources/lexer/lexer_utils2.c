/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:36:41 by baroun            #+#    #+#             */
/*   Updated: 2023/01/09 16:18:46 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v'
			|| c == '\n' || c == '\f' || c == '\r');
}

int	ft_isspcable(int c)
{
	if (ft_isspace(c) || ft_isfle(c))
		return (0);
	else
		return (1);
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
