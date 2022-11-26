/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:29:07 by emorvan           #+#    #+#             */
/*   Updated: 2022/11/23 14:33:33 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Turns $ENV into 
char    *expand_env(char *dollar_sign)
{
    char    *env_variable;

    env_variable = getenv(ft_substr(dollar_sign, 1, ft_strlen(dollar_sign)));
}