#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL long long

typedef int		(*t_cmp)(const void *, const void *);

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

#define N_MAX 100100

typedef struct s_road
{
	int				from;
	int				to;
	LL				cost;
	struct s_road	*next;
}	t_road;

typedef struct s_pair
{
	int	fst;
	LL	snd;
}	t_pair;

t_pair	*create_pair(int fst, LL snd)
{
	t_pair	*p;

	p = (t_pair *)malloc(sizeof(t_pair));
	p->fst = fst;
	p->snd = snd;
	return (p);
}

static int		g_N;
static int		g_M;

static t_road	*g_R[N_MAX];

static LL		g_cost1[N_MAX];
static LL		g_costN[N_MAX];

static bool		g_decided1[N_MAX];
static bool		g_decidedN[N_MAX];

static t_heap	*g_queue;

int	cmpair(const void *a, const void *b)
{
	t_pair	*aa;
	t_pair	*bb;

	aa = (t_pair *)a;
	bb = (t_pair *)b;
	return (aa->snd - bb->snd);
}

void	dijkstra(int start, LL *cost, bool *decided)
{
	t_pair	*pair;
	t_road	*tmp;

	cost[start] = 0;
	g_queue = heap_create(N_MAX, cmpair);
	heap_add(g_queue, create_pair(start, 0));
	while (g_queue->size > 0)
	{
		pair = heap_pop(g_queue);
		if (decided[pair->fst] || cost[pair->fst] < pair->snd)
			continue ;
		decided[pair->fst] = true;
		tmp = g_R[pair->fst];
		while (tmp != NULL)
		{
			if (!decided[tmp->to]
				&& cost[tmp->to] > cost[pair->fst] + tmp->cost)
			{
				cost[tmp->to] = cost[pair->fst] + tmp->cost;
				heap_add(g_queue, create_pair(tmp->to, cost[tmp->to]));
			}
			tmp = tmp->next;
		}
	}
}

// AとBの間の道路を作成する
void	add_road(int A, int B, LL C)
{
	t_road	*tmp;

	tmp = (t_road *)malloc(sizeof(t_road));
	tmp->from = A;
	tmp->to = B;
	tmp->cost = C;
	tmp->next = g_R[A];
	g_R[A] = tmp;
	tmp = (t_road *)malloc(sizeof(t_road));
	tmp->from = B;
	tmp->to = A;
	tmp->cost = C;
	tmp->next = g_R[B];
	g_R[B] = tmp;
}

int	main(void)
{
	int	i;
	int	A;
	int	B;
	LL	C;

	scanf("%d %d", &g_N, &g_M);
	i = -1;
	while (++i < g_M)
	{
		scanf("%d %d %lld", &A, &B, &C);
		add_road(A, B, C);
	}
	i = -1;
	while (++i <= g_N)
	{
		g_cost1[i] = 1000000000000;
		g_costN[i] = 1000000000000;
	}
	dijkstra(1, g_cost1, g_decided1);
	dijkstra(g_N, g_costN, g_decidedN);
	i = 0;
	while (++i <= g_N)
		printf("%lld\n", g_cost1[i] + g_costN[i]);
}
