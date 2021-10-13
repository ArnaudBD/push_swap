NAME =	push_swap

SRCS = 						3n_sort.c\
							5n_sort.c\
							big_sort.c\
							main.c\
							setup.c\
							stack_ops.c\
							utils.c\
							moving.c\
							distance.c\
							target.c\
							check_errors.c

OBJS =	$(SRCS:.c=.o)

CC =	gcc

CFLAG =	-g -Wall -Werror -Wextra -fsanitize=address

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