NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
RM = rm -f
AR = ar rcs

H_DIR = specifier_handlers/

SRCS = ft_printf.c\
       ft_printf_utils.c \
       $(H_DIR)c_handler.c \
       $(H_DIR)s_handler.c \
       $(H_DIR)p_x_X_handler.c \
       $(H_DIR)u_handler.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Library $(NAME) created!"

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
