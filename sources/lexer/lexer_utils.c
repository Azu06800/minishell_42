/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:16:10 by baroun            #+#    #+#             */
/*   Updated: 2022/11/16 16:05:41 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dst = malloc(len * sizeof(char));
	if (!dst)
		return (0);
	ft_memcpy(dst, s1, len);
	return (dst);
}

size_t cpt_word(char *str)
{
	size_t	i;

	i = 0;

	while (*str)
	{
		if (!ft_isspace(*str))
		{
			i++;
			while(*str && !ft_isspace(*str))
				str++;
		}
		else
			str++;
	}

}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	i = 0;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = *(s + start + i);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
