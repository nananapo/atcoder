#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_MAX 202000

static int		g_N;
static int		g_A[N_MAX];
static int		g_B[N_MAX];

typedef struct s_road
{
	int				from;
	int				to;
	struct s_road	*next;
}	t_road;

static t_road	g_road[N_MAX];
static t_road	*g_R[N_MAX];
static bool		g_visited[N_MAX];

static int		g_hist[N_MAX * 10];
static int		g_hist_index;

void	rec(int pos)
{
	t_road	*tmp;

	tmp = g_R[pos];
	g_visited[pos] = true;
	g_hist[g_hist_index++] = pos;
	while (tmp)
	{
		if (g_visited[tmp->to])
		{
			tmp = tmp->next;
			continue ;
		}
		rec(tmp->to);
		g_hist[g_hist_index++] = pos;
		tmp = tmp->next;
	}
}

t_road	*create_pair(int from, int to, t_road *next)
{
	t_road	*tmp;

	tmp = malloc(sizeof(t_road));
	tmp->from = from;
	tmp->to = to;
	tmp->next = next;
	return (tmp);
}

int	cmpf(const void *a, const void *b)
{
	t_road	*c;
	t_road	*d;

	c = (t_road *)a;
	d = (t_road *)b;
	return (d->from - c->from);
}

int	cmpt(const void *a, const void *b)
{
	t_road	*c;
	t_road	*d;

	c = (t_road *)a;
	d = (t_road *)b;
	return (d->to - c->to);
}

void	init(void)
{
	int		i;
	t_road	*tmp;

	qsort(g_road, g_N - 1, sizeof(t_road), cmpf);
	i = -1;
	while (++i < g_N - 1)
	{
		tmp = create_pair(g_road[i].to, g_road[i].from, NULL);
		tmp->next = g_R[g_road[i].to];
		g_R[g_road[i].to] = tmp;
	}
	qsort(g_road, g_N - 1, sizeof(t_road), cmpt);
	i = -1;
	while (++i < g_N - 1)
	{
		tmp = create_pair(g_road[i].from, g_road[i].to, NULL);
		tmp->next = g_R[g_road[i].from];
		g_R[g_road[i].from] = tmp;
	}
}

void	answer(void)
{
	int	i;

	i = -1;
	while (++i < g_hist_index)
	{
		printf("%d", g_hist[i]);
		if (i != g_hist_index - 1)
			printf(" ");
	}
}

int	main(void)
{
	int		i;
	t_road	*tmp;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N - 1)
	{
		scanf("%d %d", g_A + i, g_B + i);
		g_road[i].from = g_A[i];
		g_road[i].to = g_B[i];
	}
	init();
	rec(1);
	answer();
	printf("\n");
}
