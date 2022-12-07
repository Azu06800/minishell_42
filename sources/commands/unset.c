/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:40:18 by emorvan           #+#    #+#             */
/*   Updated: 2022/11/25 16:17:55 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(char **args)
{
	int	i;

	if (!args[0])
	{
		ft_putstr_fd("unset: not enough arguments\n", 2);
		return (1);
	}
	i = 0;
	while (args[i])
	{
		// If variable has been set, then delete it.
		i++;
	}
}
