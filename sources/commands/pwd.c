/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:49:40 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/17 15:01:49 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(char **token, t_minishell *minishell)
{
	char	*cur_dir;

	(void) minishell;
	(void) token;
	cur_dir = malloc(sizeof(char) * 256);
	if (getcwd(cur_dir, sizeof(char) * 256) == NULL)
		return (1);
	printf("%s\n", cur_dir);
	free(cur_dir);
	return (0);
}
