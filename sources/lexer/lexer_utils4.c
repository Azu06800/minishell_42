/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:18:29 by baroun            #+#    #+#             */
/*   Updated: 2022/12/07 17:25:29 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strlenspquote(char *arg)
{
	int	i;
	int	j;
	int	in_sq;
	int	in_dq;

	in_dq = 0;
	in_sq = 0;
	j = 0;
	i = -1;
	while(arg[++i])
	{
		if (ft_isquote(arg[i]) && (!in_sq || !in_dq))
			j += 2;
		if (arg[i] == '\'')
			in_sq = !in_sq;
		if (arg[i] == '"')
			in_dq = !in_dq;
	}
	printf("j = %d\n",j + i);
	return (i + j);
}

char    *ft_add_spcquote(char *arg)
{
    char	*r;
    int		i;
    int		j;

    i = 0;
    j = 0;
    r = malloc((ft_strlenspquote(arg)) * sizeof(char));
    while (arg[i])
    {
        if (ft_isfle(arg[i]))
        {
            r[j++] = ' ';
            r[j++] = arg[i++];
            r[j++] = ' ';
        }
        r[j++] = arg[i++];
    }
	r[j] = '\0';
    printf("r = %s\n",r);
    return (r);
}
