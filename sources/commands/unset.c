/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:40:18 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/10 18:54:40 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isalpha(char str)
{
	if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z'))
		return (1);
	if (str == '_')
		return (1);
	return (0);
}

int	ft_unset(t_parser_token *token)
{
	int	i;

	i = 0;
	while (token->command[++i])
	{
		if (ft_isalpha(token->command[i][0]) == 0)
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(token->command[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
		}
		if (ft_getenv(token->command[i]) != NULL)
			ft_delenv(token->command[i]);
	}
	return (0);
}
