/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:29:07 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/10 18:38:06 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_expander(t_parser_token *tokens)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tokens[i].type != TOKEN_END)
	{
		while (j < tokens[i].command_size)
		{
			tokens[i].command[j] = ft_expand_vars(tokens[i].command[j]);
			j++;
		}
		if (tokens[i].input)
			tokens[i].input = ft_expand_vars(tokens[i].input);
		if (tokens[i].output)
			tokens[i].output = ft_expand_vars(tokens[i].output);
		i++;
	}
}

