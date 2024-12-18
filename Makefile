NAME = get_next_line.a

CC = cc

SRCS = ./get_next_line.c ./get_next_line_utils.c

INCLUDES = get_next_line.h

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wall

all : $(NAME)

$(NAME) : $(OBJ)
		ar -rc $(NAME) $(OBJ)

.c.o :
		$(CC) $(CFLAGS) -c -I $(INCLUDES) $< -o $@

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re :
		make fclean all

.PHONY: clean fclean all re