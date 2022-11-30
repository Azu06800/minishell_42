/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:29:39 by baroun            #+#    #+#             */
/*   Updated: 2022/11/30 18:43:52 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Includes

# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <sys/wait.h>
# include <dirent.h>
# include <fcntl.h>


# define prompt "minishell$ "

//		-LEXER-
	//is
int	ft_isspace(int c);
int ft_issep(int c);
int	ft_isquote(int c);
int ft_isfle(int c);
	//malloc split
size_t	cpt_quote(char *s);
size_t cpt_word(char *str);
	//sep
int		ft_strlenspc(char *arg);
char    *ft_add_spc(char *arg);
	//split
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_lexer(char *arg);

//parsing
int	cmp_str(char *str, char *cmp);
void	ft_parsing(char **token);

//exec
void	ft_echo(char **token);
void	ft_exit(char **token);

//tester
void tester_lexer(char **token);

#endif
