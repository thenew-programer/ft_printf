LIBFT_DIR	= libft
SRCS_DIR	= src
B_SRCS_DIR	= src_bonus
OBJS_DIR	= obj
B_OBJS_DIR	= obj_bonus
TEST_DIR	= tests
HEAD		= ./includes/

LIBFT_LIB	= $(LIBFT_DIR)/libft.a

SRCS		= $(wildcard $(SRCS_DIR)/*.c)
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

B_SRCS		= $(wildcard $(B_SRCS_DIR)/*.c)
B_OBJS		= $(patsubst $(B_SRCS_DIR)/%.c, $(B_OBJS_DIR)/%.o, $(B_SRCS))

NAME		= libftprintf.a
CC			= cc
AR			= ar rcs
RM			= rm
CFLAGS		= -Wall -Werror -Wextra -I $(HEAD) -c

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
								@cp $(LIBFT_LIB) $(NAME)
								$(AR) $(NAME) $(OBJS)

bonus: $(B_OBJS) $(LIBFT_LIB)
								@cp $(LIBFT_LIB) $(NAME)
								$(AR) $(NAME) $(B_OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
								@mkdir -p $(OBJS_DIR)
								$(CC) $(CFLAGS) $< -o $@

$(B_OBJS_DIR)/%.o: $(B_SRCS_DIR)/%.c
								@mkdir -p $(B_OBJS_DIR)
								$(CC) $(CFLAGS) $< -o $@

$(LIBFT_LIB):
								@make -C $(LIBFT_DIR)

clean:
								$(RM) -rf $(OBJS_DIR)
								$(RM) -rf $(B_OBJS_DIR)
								@make clean -C $(LIBFT_DIR)

fclean: clean
								$(RM) -f $(NAME)
								@make fclean -C $(LIBFT_DIR)

re: fclean all

norm:
								@norminette $(LIBFT_DIR) $(SRCS_DIR) | grep -v Error -B1 || true

tm:
								@make m -C $(TEST_DIR)

tb:
								@make b -C $(TEST_DIR)

.PHONY: all clean fclean re norm
