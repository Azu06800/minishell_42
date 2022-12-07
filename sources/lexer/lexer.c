/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:54:34 by baroun            #+#    #+#             */
/*   Updated: 2022/12/07 14:45:16 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_lexer(char *args)
{
	size_t	i;
	int		tmp;
	char	**token;
	int		j;
	int		b;
	char	*arg;

	i = 0;
	j = 0;
	b = 0;
	arg = ft_add_spc(args);
	token = (char **)malloc(((cpt_word(arg)) + 1) * sizeof(char *));
	printf("t = %zu\n",cpt_word(arg));
	while (arg[j])
	{
		while ((arg[j] && ft_isspace(arg[j])))
			j++;
		tmp = j;
		while (arg[j] && !ft_isspace(arg[j]))
			j++;
		if (!ft_isspace(arg[j - 1]))
			token[i++] = ft_substr(arg, tmp, j - tmp);
	}
	token[i] = NULL;
	return (token);
}
