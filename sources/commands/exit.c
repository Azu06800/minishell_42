/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:10:04 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 16:23:53 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

int	ft_exit(t_parser_token *token, t_minishell *minishell)
{
	(void) minishell;
	ft_putstr_fd("exit", 2);
	ft_putstr_fd("\n", 2);
	if (token->command[1] == NULL)
		exit(0);
	if (token->command[2] == NULL)
	{
		if (!ft_is_numeric(token->command[1]))
		{
			ft_putstr_fd("bash: exit: ", 2);
			ft_putstr_fd(token->command[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(2);
		}
		else
			exit(ft_atoi(token->command[1]));
	}
	else
	{
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
		exit(1);
		return (1);
	}
	exit(0);
	return (0);
}
