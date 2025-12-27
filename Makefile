NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -I.
RM = rm -f
AR = ar rcs

H_DIR = specifier_handlers/

SRCS = ft_printf.c\
       $(H_DIR)specifier_utils.c \
       $(H_DIR)c_handler.c \
       $(H_DIR)s_handler.c \
       $(H_DIR)p_handler.c \
       $(H_DIR)i_d_handler.c \
       $(H_DIR)u_handler.c \
       $(H_DIR)x_X_handler.c

BONUS_SRCS =  ft_printf.c\
	      $(H_DIR)specifier_utils.c \
	      $(H_DIR)c_handler.c \
	      $(H_DIR)s_handler.c \
	      $(H_DIR)p_handler.c \
	      $(H_DIR)i_d_handler.c \
	      $(H_DIR)u_handler.c \
	      $(H_DIR)x_X_handler.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Library $(NAME) created!"

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
	@echo "Bonus library updated!"

clean: 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
