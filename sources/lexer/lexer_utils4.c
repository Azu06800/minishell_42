/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:18:29 by baroun            #+#    #+#             */
/*   Updated: 2022/12/09 19:35:08 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* ************************************************************************** */
/* ajoute des epaces au tour des quote                                        */
/* ************************************************************************** */

int	ft_strlen_spcqu(char *arg)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (arg[++i])
	{
		if (ft_isquote(arg[i]))
			j += 2;
	}
	return (i + j + 1);
}

char	*ft_add_spcqu(char *arg)
{
	char	*r;
	int		i;
	int		j;
	int		s;

	i = 0;
	j = 0;
	s = ft_strlen_spcqu(arg);
	r = malloc((s) * sizeof(char));
	while (s > j)
	{
		while (ft_isquote(arg[i]))
		{
			r[j++] = ' ';
			r[j++] = arg[i++];
			r[j++] = ' ';
		}
		r[j++] = arg[i++];
	}
	r[j - 1] = '\0';
	free(arg);
	return (r);
}

/* ************************************************************************** */
/* enleve les espaces autour des fleches                                      */
/* ************************************************************************** */
int	ft_strlen_rspcqu(char *arg)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (arg[++i])
	{
		if (ft_isquote(arg[i]))
			j -= 2;
	}
	return (i + j - 1);
}

char	*ft_remove_spcqu(char *arg)
{
	int		i;
	int		j;
	char	*token;

	i = 2;
	j = 0;
	token = malloc((ft_strlen_rspcqu(arg)) * sizeof(char));
	while (arg[i + 2])
	{
		while (ft_isspace(arg[i]) && ft_isquote(arg[i + 1]))
		{
			token[j++] = arg[i + 1];
			i += 3;
		}
		token[j++] = arg[i++];
	}
	token[j] = '\0';
	return (token);
}
