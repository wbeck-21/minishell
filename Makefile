NAME	= minishell

CC		= gcc
FLG 	= -g -Wall -Werror -Wextra -MMD
L_FLG = -L /Users/${USER}/.brew/opt/readline/lib 

SRC		=     main.c minishell.c do_symbol.c history.c parser.c utils.c utils_1.c utils_3.c utils_4.c redirect.c pipe.c utils_2.c lists.c init_pipe.c\
			  libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
			  libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
			  libft/ft_itoa.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c \
			  libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_lstmap.c \
			  libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_memchr.c libft/ft_memcmp.c \
			  libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
			  libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c \
			  libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c \
			  libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
			  libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c \
			  libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c \
			  libft/get_next_line_utils.c \
			  mini_bins/exec.c mini_bins/mini_cd.c mini_bins/mini_dq.c mini_bins/mini_echo.c mini_bins/mini_env.c \
			  mini_bins/mini_exit.c mini_bins/mini_export.c mini_bins/mini_history.c mini_bins/mini_pwd.c mini_bins/mini_shlvl.c \
			  mini_bins/mini_unset.c 

OBJ 	= $(SRC:.c=.o)
DF		= $(SRC:.c=.d)
RM 			= rm -rf

%.o: %.c
	$(CC) $(FLG) -o $@ -c $<

all: 		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLG) $(L_FLG) $(OBJ) -o $(NAME) -lreadline

clean:
	@$(RM) $(OBJ) $(DF)

fclean: clean
	@$(RM) $(NAME)

re: fclean all