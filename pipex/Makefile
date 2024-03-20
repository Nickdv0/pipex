NAME = pipex

CC = gcc

CFLAGS = -Wextra -Wall -Werror -I.

SRC = main.c			\
	  utils.c			\
	  command.c			\
	  error.c			\
	  close_fd.c		\
	  pipe_redirect.c	\

GNL_SRC = get_next_line/get_next_line.c			\
		  get_next_line/get_next_line_utils.c	\

HEAD_DIR = pipex.h

green = \033[1;32m # green
reset = \033[0m # reset

all: $(NAME)

$(NAME): $(SRC)
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(SRC) $(GNL_SRC) -L ft_printf -lftprintf -o $(NAME) -g -fsanitize=address
	@echo "pipex		$(green)Compiled ✓$(green)$(reset)"

clean :
	@make clean -C ft_printf
	@rm -rf pipex.dSYM
	@echo "clean		[ $(green)✓$(green)$(reset)]"

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ft_printf
	@echo "fclean		[ $(green)✓$(green)$(reset)]"

re : fclean all