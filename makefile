RED		=	\033[31m
GRE		=	\033[32m
BLU		=	\033[34m
YEL		=	\033[33m
EOC		=	\033[0m

NAME 			= minishell

SOURCES			=	./sources
INCLUDES		=	./includes
OBJECTS			=	./bin

SRCS			= tester.c\
					minishell.c\
					lexer/lexer.c\
					lexer/lexer_utils.c\
					lexer/lexer_utils2.c\
					lexer/lexer_utils3.c\
					parsing/parsing.c\
					parsing/parsing_utils.c\
					exec/ft_echo.c\
					exec/ft_exit.c\
					signal/ctrl_c.c\
					error/error.c

OBJS			=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))

CFLAGS			=	-Wall -Wextra -Werror -Iincludes
CC				=	gcc
CINCLUDES		=	-I ${INCLUDES}
LINK			=	libreadline.a -lreadline -lncurses

${OBJECTS}/%.o: ${SOURCES}/%.c
	@mkdir -p $(dir $@)
	@echo "⏳ Compilation de $(YEL)${notdir $<}$(EOC). ⏳"
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}

all: ${NAME}

${NAME}: ${OBJS}
	@echo "✅ $(GRE)Compilation terminée$(EOC) ✅"
	@${CC} ${CFLAGS} ${LINK} -o ${NAME} ${OBJS}

clean:
	@echo "🗑 $(RED)Supression des fichiers binaires (.o).$(EOC) 🗑"
	@rm -rf ${OBJECTS}

fclean: clean
	@echo "🗑 $(RED)Supression des executables et librairies.$(EOC) 🗑"
	@rm -f ${NAME}

re: fclean all

run: all
	./${NAME}

.PHONY:	all clean fclean re run
