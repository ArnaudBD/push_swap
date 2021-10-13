#include "get_next_line.h"
#include "../../push_swap.h"
#include "checker.h"

void	do_the_move(char *str, t_list **stack)
{
	t_list *current[2];

	current[0] = stack[0];
	current[1] = stack[1];
	if (ft_strncmp(str, "pa", 2) == 0)
		c_push(stack, 'a');
	if (ft_strncmp(str, "pb", 2) == 0)
		c_push(stack, 'b');
	if (ft_strncmp(str, "ra", 2) == 0)
		c_rotate(current[0]);
	if (ft_strncmp(str, "rb", 2) == 0)
		c_rotate(current[1]);
	if (ft_strncmp(str, "rr", 3) == 0)
	{
		c_rotate(current[0]);
		c_rotate(current[1]);
	}
	if (ft_strncmp(str, "rra", 3) == 0)
		c_reverse_rotate(current[0]);
	if (ft_strncmp(str, "rrb", 3) == 0)
		c_reverse_rotate(current[1]);
	if (ft_strncmp(str, "rrr", 3) == 0)
	{
		c_reverse_rotate(current[0]);
		c_reverse_rotate(current[1]);
	}
}

int	main(int argc, char const *argv[])
{
	t_list	*stack[2];
	int		fd;
	char	*line[] = {"truc"};

	fd = argc - argc;
	if (check_errors(argv) < 0)
		return (1);
	stack[0] = NULL;
	stack[1] = NULL;
	stack[0] = create_stack(stack[0], argc, argv);
show_stacks(stack[0], stack[1]);
	while (get_next_line(fd, line) == 1)
	{
		write(1, "OKay\n", 5);
		printf("|%s|\n", line[0]);
		// do_the_move(line[0], stack);
		free(line[0]);
	}
printf("OOOOOOKKKKKKKKKKAAAAAAAAAAAAAAAAAAAAAAYYYYYYYYYYYYYYYYYYY\n");
	free(line[0]);
show_stacks(stack[0], stack[1]);
	// freelist(stack);
	return (0);
}