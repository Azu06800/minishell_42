/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:29:39 by baroun            #+#    #+#             */
/*   Updated: 2022/12/21 00:48:21 by emorvan          ###   ########.fr       */
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

//-------------------STRUCT-------------------//
typedef struct s_minishell
{
	char	*path;
	char	**env;
	char	**builtins;
	size_t	last_token_size;
}	t_minishell;

typedef enum e_token_type
{
	TOKEN_CMD,
	TOKEN_REDIR,
	TOKEN_SEP,
	TOKEN_END
}	t_token_type;

typedef enum e_redirection_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
	REDIR_PIPE,
	REDIR_ERROR
}	t_redir_type;

typedef struct s_parser_token
{
	t_token_type		type;
	t_redir_type		redirection[5];
	char				**command;
	size_t				command_size;
	char				**input;
	size_t				input_size;
	char				**output;
	size_t				output_size;
}	t_parser_token;

//-------------------LEXER-------------------//
	//is
int				ft_isspace(int c);
int				ft_issep(int c);
int				ft_isquote(int c);
int				ft_isfle(int c);
	//malloc split
size_t			cpt_quote(char *s);
size_t			cpt_word(char *str, int a);
	//sep
char			*ft_remove_spcqu(char *arg);
char			*ft_add_spcqu(char *arg);
char			*ft_remove_spc(char *arg);
char			*ft_add_spc(char *arg);
char			*ft_remove_bslash(char *arg);
int				ft_strlenrslash(char *arg);
	//split
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			**ft_lexer(char *arg);
char			**ft_lasttoken(char **token);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
int				is_arrow(char *token);
char			*concat_tokens(char *token1, char *token2);
void			compact_array(char **token, int j, int i);

//-------------------PARSER-------------------//
int				cmp_str(char *str, char *cmp);
void			ft_parsing(char **token, t_minishell *minishell);
t_parser_token	*ft_parse_tokens(char **tokens, t_minishell *minishell);
void			print_token(t_parser_token *token);
void			parse_redirect_token(char *token, t_parser_token *parsed_token);
void			parse_separator_token(char *token, t_parser_token *parsed_tok);
void			parse_command_token(char **tk, size_t i, t_parser_token *p_tk);
int				is_redirect(char *token);
t_redir_type	get_redir_type(char *token);

//------------------COMMANDS------------------//
int				ft_cd(char **token, t_minishell *minishell);
int				ft_echo(char **token, t_minishell *minishell);
int				ft_env(char **token, t_minishell *minishell);
int				ft_export(char **token, t_minishell *minishell);
int				ft_pwd(char **token, t_minishell *minishell);
int				ft_unset(char **token, t_minishell *minishell);
void			ft_exit(char **token, t_minishell *minishell);

//-------------------SIGNAL-------------------//
void			init_signal(void);

//-------------------ERROR-------------------//
int				error_quote(char *str);
int				err_unclosed_quote(char *str);
char			**listofcmd(void);
int				check_cmd(char *str, t_minishell *minishell);
int				ft_cmdcmp(char *s1, char **s2);
int				ft_strcmp(const char *s1, const char *s2);

//-------------------UTILS-------------------//
int				ft_onlyspace(char *str);
int				ft_cinstr(char *str, char c);
size_t			ft_strlen(const char *str);

#endif
