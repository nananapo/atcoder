#include <stdio.h>
#include <stdlib.h>

typedef int	(*t_cmp)(const void *, const void *);

typedef struct s_heap
{
	void	**list;
	int		size;
	t_cmp	cmp;
}	t_heap;

// ヒープを作成する
t_heap	*heap_create(int max_size, t_cmp cmp)
{
	t_heap	*heap;

	heap = (t_heap *)malloc(sizeof(t_heap));
	heap->list = malloc(sizeof(void *) * max_size);
	heap->size = 0;
	heap->cmp = cmp;
	return (heap);
}

// ヒープに要素を追加する
void	heap_add(t_heap *heap, void *value)
{
	int	index;

	heap->list[heap->size++] = value;
	index = heap->size;
	while (index != 1
		&& heap->cmp(heap->list[index / 2 - 1], value) > 0)
	{
		heap->list[index - 1] = heap->list[index / 2 - 1];
		heap->list[index / 2 - 1] = value;
		index = index / 2;
	}
}

// ヒープの最小要素を取得する
void	*heap_peek(t_heap *heap)
{
	return (heap->list[0]);
}

// ヒープの最小要素を取得して削除する
void	*heap_pop(t_heap *heap)
{
	void	*result;
	int		index;
	int		mindex;
	void	*tmp;

	result = heap->list[heap->size-- == -1];
	if (heap->size != 0)
	{
		heap->list[0] = heap->list[heap->size];
		index = 1;
		while (index * 2 <= heap->size)
		{
			mindex = index * 2 - 1;
			if (index * 2 <= heap->size
				&& heap->cmp(heap->list[mindex + 1], heap->list[mindex]) < 0)
				mindex = index * 2;
			if (heap->cmp(heap->list[mindex], heap->list[index - 1]) >= 0)
				break ;
			tmp = heap->list[index - 1];
			heap->list[index - 1] = heap->list[mindex];
			heap->list[mindex] = tmp;
			index = mindex + 1;
		}
	}
	return (result);
}

/*
int	cmpint(const void *a, const void *b)
{
	return (*((int *)a) - *((int *)b));
}

int	main(void)
{
	int		i;
	t_heap	*test;
	int		*tmp;

	test = heap_create(1000, cmpint);
	i = -1;
	while (++i < 1000)
	{
		tmp = (int *)malloc(sizeof(int));
		*tmp = i;
		heap_add(test, tmp);
	}
	i = -1;
	while (++i < 1000)
		printf("Pop %d\n", *(int *)heap_pop(test));
}
*/
