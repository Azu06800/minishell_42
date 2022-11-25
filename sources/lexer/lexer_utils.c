/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:16:10 by baroun            #+#    #+#             */
/*   Updated: 2022/11/25 20:12:22 by baroun           ###   ########.fr       */
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	d = dst;
	s = src;
	while (n--)
		d[n] = s[n];
	return (dst);
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
    size_t    i;
    int        a;

    i = 0;
    a = 0;

    while (str[a])
    {
        if (ft_issep(str[a]))
          i++;
        if (!ft_isspace(str[a]) && !ft_issep(str[a]))
        {
            i++;
            while(str[a] && !ft_isspace(str[a]) && !ft_issep(str[a])) 
                a++;
        }
        else
            a++;
    }
    return (i + cpt_quote(str));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	i = 0;
	dst = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		dst[i] = *(s + start + i);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
