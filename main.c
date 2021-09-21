#include "push_swap.h"

// t_list	*create_stack(t_list *stack, int argc, const char **argv);
// void    push(t_list **stack, char dest);


int main(int argc, char const *argv[])
{
	t_list	*stack[2];
	t_list *current[2];
	
	stack[0] = NULL;
	stack[1] = NULL;
	stack[0] = create_stack(stack[0], argc, argv);
	current[0] = stack[0];
	while(current[0] != NULL)
	{
		printf("number   == %d\n", current[0]->value);
		printf("position == %d\n\n", current[0]->pos);
		current[0] = current[0]->next;
	}

	stack[0] = swap(stack[0]);
	
	current[0] = stack[0];
	while(current[0] != NULL)
	{
		printf("number   == %d\n", current[0]->value);
		printf("position == %d\n\n", current[0]->pos);
		current[0] = current[0]->next;
	}

	stack[0] = rotate(stack[0]);

	current[0] = stack[0];
	while(current[0] != NULL)
	{
		printf("number   == %d\n", current[0]->value);
		printf("position == %d\n\n", current[0]->pos);
		current[0] = current[0]->next;
	}

	push(stack, 'a');

	current[0] = stack[0];
	while(current[0] != NULL)
	{
		printf("number   == %d\n", current[0]->value);
		printf("position == %d\n\n", current[0]->pos);
		current[0] = current[0]->next;
	}


	return 0;
}