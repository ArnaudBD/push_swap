#include "push_swap.h"

void	show_stacks(t_list *stacka, t_list *stackb)
{
	int		diff;
	t_list	*current[2];

	current[0] = stacka;
	current[1] = stackb;
	diff = stack_size(stacka) - stack_size(stackb);
	while (diff > 0 && current[0] != NULL)
	{
		printf("%2d\n", current[0]->value);
		current[0] = current[0]->next;
		diff--;
	}
	while (diff < 0 && current[1] != NULL)
	{
		printf("   %2d\n", current[1]->value);
		current[1] = current[1]->next;
		diff++;
	}
	while (current[0] != NULL && current[1] != NULL)
	{
		printf("%2d %2d\n", current[0]->value, current[1]->value);
		current[0] = current[0]->next;
		current[1] = current[1]->next;
	}
	printf("-- --\n");
	printf("a   b\n\n\n");
	return ;
}
