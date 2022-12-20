RED		=	\033[31m
GRE		=	\033[32m
BLU		=	\033[34m
YEL		=	\033[33m
EOC		=	\033[0m

NAME 			= minishell

SOURCES			=	./sources
OBJECTS			=	./bin

SRCS			=	minishell.c\
					$(addprefix lexer/, lexer.c lexer_utils.c lexer_utils2.c lexer_utils3.c lexer_utils4.c)\
					$(addprefix parsing/, parsing.c)\
					$(addprefix signal/, signal.c)\
					$(addprefix env/, env.c env_utils.c)\
					$(addprefix commands/, cd.c echo.c env.c exit.c export.c pwd.c unset.c)\
					$(addprefix expander/, expander.c)\
					$(addprefix utils/, memory.c string.c string2.c utils.c)\
					$(addprefix error/, error.c error_utils.c)


OBJS			=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))

CFLAGS			=	-Wall -Wextra -Werror -Iincludes -arch x86_64
CC				=	gcc
CINCLUDES		=	-I ./includes
LINK			=	libreadline.a -lreadline -lncurses

${OBJECTS}/%.o: ${SOURCES}/%.c
	@if [ ! -d "includes/readline" ]; then make rl; fi
	@mkdir -p $(dir $@)
	@echo "⏳ Compilation de $(YEL)${notdir $<}$(EOC). ⏳"
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}

all: ${NAME}
	

rl:
	@rm -rf req.sh
	@rm -rf t
	@echo "touch readline-8.1.tar.gz" >> req.sh
	@echo "⏳ Creation de $(YEL)libreadline$(EOC). ⏳"
	@echo "curl -ks https://ftp.gnu.org/gnu/readline/readline-8.1.tar.gz > readline-8.1.tar.gz" >> req.sh
	@echo "(tar -xf readline-8.1.tar.gz) >> t"  >> req.sh
	@echo "mv readline-8.1 readline" >> req.sh
	@echo "rm -rf readline-8.1.tar.gz" >> req.sh
	@echo "mv readline includes" >> req.sh
	@echo "cd includes/readline/" >> req.sh
	@echo "(./configure --prefix=$$(pwd)/includes/readline) >> t" >> req.sh
	@echo "make && make install && make clean" >> req.sh
	@echo "rm -rf t" >> req.sh
	@echo "cd ../../" >> req.sh
	@echo "clear" >> req.sh
	@sh req.sh
	@rm -rf req.sh
	@rm -rf t
	@stty -echoctl
	@echo "✅ $(GRE)Creation de libreadline terminée.$(EOC) ✅"

${NAME}: ${OBJS}
	@echo "✅ $(GRE)Compilation terminée.$(EOC) ✅"
	@${CC} ${CFLAGS} ${LINK} -o ${NAME} ${OBJS}

clean:
	@echo "🗑  $(RED)Supression des fichiers binaires (.o).$(EOC) 🗑"
	@rm -rf ${OBJECTS}

fclean: clean
	@echo "🗑  $(RED)Supression des executables et librairies.$(EOC) 🗑"
	@rm -rf includes/readline
	@rm -f ${NAME}

re: fclean all

run: all
	./${NAME}

.PHONY:	all clean fclean re run
