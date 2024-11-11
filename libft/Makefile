SRCS_DIR	= src
OBJS_DIR	= obj
HEAD		= ../includes/

SRCS		= ${wildcard $(SRCS_DIR)/*.c}
OBJS		= ${patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS)}

NAME		= libft.a

CC			= cc
RM			= rm -rf
AR			= ar rcs
CFLAGS		= -Wall -Wextra -Werror -I $(HEAD) -c

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			@mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
