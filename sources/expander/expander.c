/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:29:07 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 13:14:48 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;

	copy = malloc(n + 1);
	if (copy == NULL)
		return (NULL);
	copy[n] = '\0';
	return ((char *)ft_memcpy(copy, s1, n));
}

static void	ft_expander_dollar(t_parser_token *token, t_minishell *minishell,
	int i)
{
	char	*expanded_var;
	int		j;
	int		k;
	char	*var_name;

	j = 0;
	var_name = "";
	expanded_var = "";
	while (token->command[i][j])
	{
		if (token->command[i][j] == '$')
		{
			k = j + 1;
			while (ft_isalnum(token->command[i][k]))
			{
				var_name = ft_strndup(token->command[i] + j + 1, k - j - 1);
				expanded_var = ft_getenv(minishell, var_name);
				if (expanded_var != NULL)
				{
					token->command[i] = ft_strndup(token->command[i], j);
					token->command[i] = ft_strjoin(token->command[i], expanded_var);
					token->command[i] = ft_strjoin(token->command[i], token->command[i] + k + 1);
					free(var_name);
					var_name = "";
					expanded_var = "";
					break ;
				}
				k++;
			}
			if (expanded_var == NULL)
				j++;
		}
		else
			j++;
	}
}


void	ft_expander(t_parser_token *token, t_minishell *minishell)
{
	(void)token;
	(void)minishell;
	(void)ft_expander_dollar;
	//int	i;
//
	//i = 0;
	//while (token->command[i])
	//{
	//	if (ft_strchr(token->command[i], '$'))
	//		ft_expander_dollar(token, minishell, i);
	//	i++;
	//}
}
