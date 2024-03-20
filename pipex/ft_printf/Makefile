NAME = libftprintf.a
CC = gcc
CFLAGS = -Wextra -Wall -Werror
SRCS = src/ft_print_ptr.c		\
       src/ft_print_unsint.c	\
       src/ft_printf_chrstr.c	\
       src/ft_printf_int.c		\
       src/ft_printft_hex.c		\
       src/libftprintf.c		\

LIBFT = libft
RM = rm -f
AR = ar rcs

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

green = \033[1;32m # green
reset = \033[0m # reset

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "ft_printf	$(green)Compiled ✓$(green)$(reset)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT)

clean :
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)/libft.a

re : fclean all