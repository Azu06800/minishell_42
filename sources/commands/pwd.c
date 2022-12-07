/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:49:40 by emorvan           #+#    #+#             */
/*   Updated: 2022/11/16 18:34:15 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(void)
{
	char	*cur_dir;

	cur_dir = malloc(sizeof(char) * 256);
	if (getcwd(cur_dir, sizeof(char) * 256) == NULL)
		return (1);
	printf("%s", cur_dir);
	return (0);
}
