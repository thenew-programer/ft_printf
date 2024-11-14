LIBFT_DIR	= libft
SRCS_DIR	= src
OBJS_DIR	= obj
TEST_DIR	= tests
HEAD		= ./includes/


LIBFT_LIB	= $(LIBFT_DIR)/libft.a
SRCS		= $(wildcard $(SRCS_DIR)/*.c)
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

NAME		= libftprintf.a

CC			= cc
AR			= ar rcs
RM			= rm
CFLAGS		= -Wall -Werror -Wextra -I $(HEAD) -c

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
			@mv $(LIBFT_LIB) $(NAME)
			$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			@mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) $< -o $@

$(LIBFT_LIB):
			@make -C $(LIBFT_DIR)

bonus:	$(NAME)

clean:
	$(RM) -rf $(OBJS_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

norm:
	@norminette $(LIBFT_DIR) $(SRCS_DIR) | grep -v Error -B1 || true

test:
	@make -C $(TEST_DIR)

.PHONY: all clean fclean re norm
