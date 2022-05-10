#include <stdio.h>

#define N_MAX 101000

static int	g_N;
static int	g_Q;

static int	g_next[N_MAX];
static int	g_prev[N_MAX];

void	q1(int x, int y)
{
	g_next[x] = y;
	g_prev[y] = x;
}

void	q2(int x, int y)
{
	g_next[x] = 0;
	g_prev[y] = 0;
}

void	q3(int x)
{
	int	tmp;
	int	size;

	while (g_prev[x] != 0)
		x = g_prev[x];
	tmp = x;
	size = 1;
	while (g_next[tmp] != 0)
	{
		tmp = g_next[tmp];
		size++;
	}
	printf("%d %d", size, x);
	tmp = x;
	while (g_next[tmp] != 0)
	{
		tmp = g_next[tmp];
		printf(" %d", tmp);
	}
	printf("\n");
}

int	main(void)
{
	int	q;
	int	x;
	int	y;
	int	i;

	scanf("%d %d", &g_N, &g_Q);
	i = -1;
	while (++i < g_Q)
	{
		scanf("%d %d", &q, &x);
		if (q == 3)
		{
			q3(x);
			continue ;
		}
		scanf("%d", &y);
		if (q == 1)
			q1(x, y);
		else
			q2(x, y);
	}
}
