/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:54:34 by baroun            #+#    #+#             */
/*   Updated: 2022/11/16 16:06:48 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**lexer(char *arg)
{
	size_t		len;
	size_t		i;
	const char	*start;
	char		**token;
	int			j;

	i = 0;
	j = 0;

	token = (char **)malloc(((cpt_sep(arg)) + 1) * sizeof(char *));
	
	while (arg[j])
	{
		while (arg[j] && (ft_issep(*arg)))
			j++;
		start = arg[j];
		len = 0;
		while (arg[j] && ft_issep(arg[j]) && (int)len++ != -1)
			arg++;
		if (!ft_issep(arg[i - 1]))
			token[i++] = ft_substr(start, 0, len);
	}
	token[i] = 0;
	return (token);
}
