/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:49:40 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 16:27:16 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_parser_token *token, t_minishell *minishell)
{
	char	*cur_dir;

	(void) minishell;
	(void) token;
	cur_dir = malloc(sizeof(char) * 256);
	if (getcwd(cur_dir, sizeof(char) * 256) == NULL)
	{
		exit(1);
		return (1);
	}
	printf("%s\n", cur_dir);
	free(cur_dir);
	exit(0);
	return (0);
}
