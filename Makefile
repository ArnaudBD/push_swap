NAME =	push_swap

SRCS = 						3n_sort.c\
							5n_sort.c\
							big_sort.c\
							main.c\
							setup.c\
							split.c\
							stack_ops.c\
							utils.c

OBJS =	$(SRCS:.c=.o)

CC =	gcc

CFLAG =	-Wall -Werror -Wextra

RM = 	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $^ -o $(NAME)

all : $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY :
		all clean fclean re