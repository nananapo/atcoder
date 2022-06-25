#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct	s_stack
{
	void	**values;
	int		size;
	int		max_size;
}	t_stack;

t_stack	*stack_new(int size)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	tmp->values = (void **)malloc(sizeof(void *) * size);
	tmp->size = 0;
	tmp->max_size = size;
	return (tmp);
}

void	stack_push(t_stack *stack, void *value)
{
	if (tmp->size == tmp->max_size)
	{
		fprintf(stderr, "overflow");
		return ;
	}
	stack->values[tmp->size++] = value;
}

void	*stack_pop(t_stack *stack)
{
	if (tmp->size == 0)
	{
		fprintf(stderr, "underflow");
		return ;
	}
	return (stack->values[--tmp->size]);
}
