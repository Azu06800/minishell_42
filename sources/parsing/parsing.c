/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:26:52 by baroun            #+#    #+#             */
/*   Updated: 2022/12/14 15:38:50 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parsing(char **token)
{
	if (cmp_str(token[0], "echo"))
		ft_echo(token);
	else if (cmp_str(token[0], "cd"))
		ft_cd(token);
	else if (cmp_str(token[0], "pwd"))
		ft_pwd(token);
	else if (cmp_str(token[0], "export"))
		ft_export(token);
	else if (cmp_str(token[0], "unset"))
		ft_unset(token);
	else if (cmp_str(token[0], "env"))
		ft_env(token);
	else if (cmp_str(token[0], "exit"))
		ft_exit(token);
}
