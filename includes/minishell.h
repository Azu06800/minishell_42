/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:29:39 by baroun            #+#    #+#             */
/*   Updated: 2022/12/14 16:34:58 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//------------------INCLUDES------------------//

# include <stdio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/signal.h>

typedef struct s_minishell
{
	char	*path;
	char	**env;
	char	**builtins;
}	t_minishell;

int		ft_isfle(int c);
int		ft_isspace(int c);
int		is_in_env(char *cmd, t_minishell *ms);
void	set_path(t_minishell *ms);
char	*get_path(t_minishell *ms);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

// COMMANDS
int		ft_cd(char *cmd);
int		ft_echo(char **token);
int		ft_env(void);
int		ft_export(char *cmd);
int		ft_pwd(void);
int		ft_unset(char **token);

// LEXER
int		ft_isspace(int c);
int		ft_issep(int c);
int		ft_isquote(int c);
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
char    **ft_lasttoken(char **token);

// PARSER
int		cmp_str(char *str, char *cmp);
void	ft_parsing(char **token);

// EXEC
void	ft_exit(char **token);

//-------------------SIGNAL-------------------//
void	ctr_c(int sig);

//-------------------ERROR-------------------//
int		error_quote(char *str);
char **listofcmd(void);
int		check_cmd(char *str);
int		ft_cmdcmp(char *s1, char **s2);
int	ft_strcmp(const char *s1, const char *s2);


//tester
void tester_lexer(char **token);

#endif
