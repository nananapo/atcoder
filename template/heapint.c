#include <stdio.h>
#include <stdlib.h>

typedef struct s_heap
{
	int	*list;
	int	size;
}	t_heap;

// ヒープを作成する
t_heap	*heap_create(int max_size)
{
	t_heap	*heap;

	heap = (t_heap *)malloc(sizeof(t_heap));
	heap->list = (int *)malloc(sizeof(int) * max_size);
	heap->size = 0;
	return (heap);
}

// ヒープに要素を追加する
//
// 最後尾(最も下で右側)に追加して、小さな要素を上げていく
// 根を1にすると、左側の要素は2^深さになる
// 上の要素は割る2になる(なんで？ -> 2倍ずつ要素が増えていくから)
void	heap_add(t_heap *heap, int value)
{
	int	index;

	heap->list[heap->size++] = value;
	index = heap->size;
	while (index != 1 && heap->list[index / 2 - 1] > value)
	{
		heap->list[index - 1] = heap->list[index / 2 - 1];
		heap->list[index / 2 - 1] = value;
		index = index / 2;
	}
}

// ヒープの最小要素を取得する
int	heap_peek(t_heap *heap)
{
	return (heap->list[0]);
}

// ヒープの最小要素を取得して削除する
// 最後尾の要素を根にして下げていく
// 左側の根のindexがsizeより大きいなら終了
// 
// heap->size-- == -1は常に0
int	heap_pop(t_heap *heap)
{
	int	result;
	int	index;
	int	mindex;
	int	tmp;

	result = heap->list[heap->size-- == -1];
	if (heap->size != 0)
	{
		heap->list[0] = heap->list[heap->size];
		index = 1;
		while (index * 2 <= heap->size)
		{
			mindex = index * 2 - 1;
			if (index * 2 <= heap->size
				&& heap->list[mindex + 1] < heap->list[mindex])
				mindex = index * 2;
			if (heap->list[mindex] >= heap->list[index - 1])
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
int	main(void)
{
	int		i;
	t_heap	*test;

	test = heap_create(1000);
	i = -1;
	while (++i < 1000)
		heap_add(test, i);
	i = -1;
	while (++i < 1000)
		printf("Pop %d\n", heap_pop(test));
}
*/
