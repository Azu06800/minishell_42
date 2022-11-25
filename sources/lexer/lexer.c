/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:54:34 by baroun            #+#    #+#             */
/*   Updated: 2022/11/25 20:18:44 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	other_quote(char *s, int j)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	j--;
	while (i != j)
	{
		if (ft_isquote(s[i]))
			k++;
		i++;
	}
	if (k%2 == 0)
		return (0);
	else
		return (1);
}

char	**ft_lexer(char *arg)
{
	size_t	i;
	int		tmp;
	char	**token;
	int		j;
	int		b;

	i = 0;
	j = 0;
	b = 0;
	token = (char **)malloc(((cpt_word(arg)) + 1) * sizeof(char *));
	printf("t = %zu\n",cpt_word(arg)); //gerer quote
	printf("s = %zu\n",cpt_word(arg) - cpt_quote(arg));
	while (arg[j])
	{
		while ((arg[j] && ft_isspace(arg[j])) || b)
			j++;
		tmp = j;
		while ((arg[j] && !ft_isspace(arg[j]) && !ft_issep(arg[j + 1]) && !ft_issep(arg[j])) || b)
		{
			if (ft_isquote(arg[j]))
				b = !b;
			j++;
		}
		if (ft_issep(arg[j + 1]) || ft_issep(arg[j]))
			j++;
		if (!ft_isspace(arg[j - 1] || ft_isquote(arg[j])))
			token[i++] = ft_substr(arg, tmp, j - tmp);
	}
	token[i] = NULL;
	return (token);
}
