#include "push_swap.h"

void	show_stacks(t_list *stacka, t_list *stackb)
{
	int diff;
	t_list	*current[2];

	current[0] = stacka;
	current[1] = stackb;

	diff = stack_size(stacka) - stack_size(stackb);
	printf("diff = %d\n\n", diff);
	while(diff > 0 && current[0] != NULL)
	{
		printf("%2d\n", current[0]->value);
		current[0] = current[0]->next;
		diff--;
	}
	while(diff < 0 && current[1] != NULL)
	{
		printf("   %2d\n", current[1]->value);
		current[1] = current[1]->next;
		diff++;
	}
	while(current[0] != NULL && current[1] != NULL)
	{
		printf("%2d %2d\n", current[0]->value, current[1]->value);
		current[0] = current[0]->next;
		current[1] = current[1]->next;
	}
	printf("-- --\n");
	printf("a   b\n\n\n");
	return ;
}

int main(int argc, char const *argv[])
{
	t_list	*stack[2];
	t_list	*current[2];

	stack[0] = NULL;
	stack[1] = NULL;
	stack[0] = create_stack(stack[0], argc, argv);

	show_stacks(stack[0], stack[1]);

	if(count_int(stack[0]) == 3)
	{
		stack[0] = three_numbers_sort(stack[0]);
		printf("count_int == %d\n\n", count_int(stack[0]));
	}
	else
		big_sort(stack);
		
	printf("-----------------------------sorted?-------------------------------\n");

	show_stacks(stack[0], stack[1]);

	current[1] = stack[1];
	while (current[1])
	{
		printf("number == %d\ntarget == %d\nposition == %d\nup == %d\ndist == %d\n\n", current[1]->value, current[1]->target, current[1]->pos, current[1]->up, current[1]->dist);
		current[1] = current[1]->next;
	}
	





















	// t_list *current[2];
	// current[0] = stack[0];
	// current[0] = stack[0];
	// while(current[0] != NULL)
	// {
	// 	printf("A number   == %d\n", current[0]->value);
	// 	printf("A position == %d\n", current[0]->pos);
	// 	printf("A target == %d\n\n", current[0]->target);
	// 	current[0] = current[0]->next;
	// }
	// 	current[1] = stack[1];
	// while(current[1] != NULL)
	// {
	// 	printf("B number   == %d\n", current[1]->value);
	// 	printf("B position == %d\n", current[1]->pos);
	// 	printf("B target == %d\n\n", current[1]->target);
	// 	current[1] = current[1]->next;
	// }
// while (current[0] != NULL)
// {
// 		printf("number   == %d\n", current[0]->value);
// 		printf("position == %d\n", current[0]->pos);
// 	 	printf("target == %d\n\n", current[0]->target);
// 	current[0] = current[0]->next;
// }

// 	current[1] = stack [1];
// 		while(current[1] != NULL)
// 	{
// 		printf("b_number   == %d\n", current[1]->value);
// 		printf("b_position == %d\n\n", current[1]->pos);
// 		current[1] = current[1]->next;
// 	}

// printf("-----------------------------------------------\n");
// 	stack[0] = swap(stack[0]);
	
// 	current[0] = stack[0];
// 	while(current[0] != NULL)
// 	{
// 		printf("swapped_number   == %d\n", current[0]->value);
// 		printf("swapped_position == %d\n\n", current[0]->pos);
// 		current[0] = current[0]->next;
// 	}

// printf("-----------------------------------------------\n");
// 	stack[0] = rotate(stack[0]);

// 	current[0] = stack[0];
// 	while(current[0] != NULL)
// 	{
// 		printf("rotated_number   == %d\n", current[0]->value);
// 		printf("rotated_position == %d\n\n", current[0]->pos);
// 		current[0] = current[0]->next;
// 	}

// printf("-----------------------------------------------\n");
// 	push(stack, 'b');
// 	current[0] = stack[0];
// 	while(current[0] != NULL)
// 	{
// 		printf("pushed_number   == %d\n", current[0]->value);
// 		printf("pushed_position == %d\n\n", current[0]->pos);
// 		current[0] = current[0]->next;
// 	}

// printf("-----------------------------------------------\n");
// 	stack[0] = reverse_rotate(stack[0]);
// 		current[0] = stack[0];
// 	while(current[0] != NULL)
// 	{
// 		printf("reverse_r_number   == %d\n", current[0]->value);
// 		printf("reverse_r_position == %d\n\n", current[0]->pos);
// 		current[0] = current[0]->next;
// 	}

	return 0;
}