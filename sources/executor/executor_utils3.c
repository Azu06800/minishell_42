/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:58:46 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 19:14:15 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	heredoc_perror(void)
{
	perror("minishell: error reading heredoc");
	exit(1);
}

char	*ft_heredocboucle(char *delimiter, char *line, int len, \
char *heredoc_content)
{
	char	*tmp;
	int		delimiter_len;

	delimiter_len = ft_strlen(delimiter);
	while (1)
	{
		line = readline("heredoc> ");
		if (line == NULL)
			break ;
		len = ft_strlen(line);
		if (len == delimiter_len && ft_strncmp(line, delimiter, delimiter_len)
			== 0)
		{
			free(line);
			break ;
		}
		tmp = ft_realloc(heredoc_content, ft_strlen(heredoc_content) + len + 2);
		if (tmp == NULL)
			heredoc_perror();
		heredoc_content = tmp;
		ft_strcat(heredoc_content, line);
		ft_strcat(heredoc_content, "\n");
		free(line);
	}
	return (heredoc_content);
}

char	*read_heredoc(char *delimiter)
{
	char	*line;
	int		len;
	char	*heredoc_content;

	line = NULL;
	len = 0;
	heredoc_content = malloc(1);
	if (heredoc_content == NULL)
	{
		perror("minishell: error allocating memory for heredoc content");
		exit(1);
	}
	heredoc_content[0] = '\0';
	heredoc_content = ft_heredocboucle(delimiter, line, len, heredoc_content);
	return (heredoc_content);
}
