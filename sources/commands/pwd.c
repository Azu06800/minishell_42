/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:49:40 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/14 17:53:16 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(char **token)
{
	(void) token;
	char	*cur_dir;

	cur_dir = malloc(sizeof(char) * 256);
	if (getcwd(cur_dir, sizeof(char) * 256) == NULL)
		return (1);
	printf("%s\n", cur_dir);
	return (0);
}
