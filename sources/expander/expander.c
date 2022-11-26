/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:29:07 by emorvan           #+#    #+#             */
/*   Updated: 2022/11/26 11:08:45 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Expand $VARIABLES to their value
char	*expand_env(char *dollar_sign)
{
	char	*env_variable;

	env_variable = getenv(ft_substr(dollar_sign, 1, ft_strlen(dollar_sign)));
	return (env_variable);
}
