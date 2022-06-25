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

void	enqueue_tail(t_queue *queue, void *value)
{
	queue->values[queue->tail] = value;
	if (queue->tail == queue->max_size - 1)
		queue->tail = 0;
	else
		queue->tail++;
}

void	enqueue_head(t_queue *queue, void *value)
{
	if (queue->head == 0)
		queue->head = queue->max_size - 1;
	else
		queue->head--;
	queue->values[queue->head] = value;
}

void	*dequeue_head(t_queue *queue)
{
	void	*ret;

	ret = queue->values[queue->head];
	if (queue->head == queue->max_size - 1)
		queue->head = 0;
	else
		queue->head++;
	return (ret);
}

void	*dequeue_tail(t_queue *queue)
{
	void	*ret;

	ret = queue->values[queue->tail];
	if (queue->tail == 0)
		queue->tail = queue->max_size - 1;
	else
		queue->tail--;
	return (ret);
}
