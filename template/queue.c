#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct s_queue
{
	void	**values;
	int		head;
	int		tail;
	int		max_size;
}	t_queue;

t_queue	*queue_new(int size)
{
	t_queue	*tmp;

	tmp = (t_queue *)malloc(sizeof(t_queue));
	tmp->values = (void **)malloc(sizeof(void *) * size);
	tmp->head = 0;
	tmp->tail = 0;
	tmp->max_size = size;
	return (tmp);
}

void	enqueue(t_queue *queue, void *value)
{
	if (queue->head == queue->tail + 1
		|| (queue->tail == queue->max_size - 1 && queue->head == 0))
	{
		fprintf(stderr, "overflow");
		return ;
	}
	queue->values[queue->tail] = value;
	if (queue->tail == queue->max_size - 1)
		queue->tail = 0;
	else
		queue->tail++;
}

void	*dequeue(t_queue *queue)
{
	if (queue->head == queue->tail)
	{
		fprintf(stderr, "underflow");
		return (NULL);
	}
	return (queue->values[queue->head++]);
}
