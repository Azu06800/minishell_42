/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:54:34 by baroun            #+#    #+#             */
/*   Updated: 2022/11/16 18:57:13 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**lexer(char *arg)
{
	size_t		len;
	size_t		i;
	int			tmp;
	char		**token;
	int			j;

	i = 0;
	j = 0;
	token = (char **)malloc(((cpt_word(arg)) + 1) * sizeof(char *));
	while (arg[j])
	{
		while (arg[j] && ft_issep(arg[j]))
			j++;
		len = 0;
		tmp = j;
		while (arg[j] && !ft_issep(arg[j]) && (int)len++ != -1)
			j++;
		if (!ft_issep(arg[j - 1]))
			token[i++] = ft_substr(arg + tmp, 0, len);
	}
	token[i] = NULL;
	return (token);
}
