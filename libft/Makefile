# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 18:17:10 by emorvan           #+#    #+#              #
#    Updated: 2022/11/15 11:17:13 by emorvan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			=	src/memory/ft_memcmp.c src/memory/ft_bzero.c src/memory/ft_memcpy.c \
					src/memory/ft_memchr.c src/memory/ft_memset.c src/memory/ft_memmove.c \
					src/memory/ft_calloc.c src/converter/ft_atoi.c src/converter/ft_itoa.c \
					src/io/ft_putstr_fd.c src/io/ft_putnbr_fd.c src/io/ft_printf.c \
					src/io/get_next_line.c src/io/utils/ft_printf_utils.c src/io/utils/handle_unsigned.c \
					src/io/utils/handle_ptr.c src/io/utils/handle_hex.c src/io/ft_putendl_fd.c \
					src/io/ft_putchar_fd.c src/list/ft_lstadd_back.c src/list/ft_lstnew.c src/list/ft_lstlast.c \
					src/list/ft_lstclear.c src/list/ft_lstiter.c src/list/ft_lstmap.c src/list/ft_lstsize.c \
					src/list/ft_lstadd_front.c src/list/ft_lstdelone.c src/string/ft_strnstr.c src/string/ft_strlcpy.c \
					src/string/ft_strlen.c src/string/ft_strlenc.c src/string/ft_strchr.c src/string/ft_striteri.c \
					src/string/ft_strjoin.c src/string/ft_toupper.c src/string/ft_split.c src/string/ft_strrchr.c \
					src/string/ft_strncmp.c src/string/ft_strmapi.c src/string/ft_strtrim.c src/string/ft_strlcat.c \
					src/string/ft_strdup.c src/string/ft_tolower.c src/check/ft_isdigit.c src/string/ft_substr.c \
					src/check/ft_isprint.c src/check/ft_isalpha.c src/check/ft_isalnum.c src/check/ft_isascii.c

OBJS			= $(SRCS:.c=.o)
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -arch x86_64

.c.o:
				$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
				ranlib $(NAME)

all:			$(NAME)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
