#include <stdio.h>
#include <stdbool.h>

#define N_MAX 11

static int	g_N;
static int	g_A[N_MAX][N_MAX];
static int	g_M;
static bool	g_X[N_MAX][N_MAX];

static bool	g_use[N_MAX];

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	rec(int	i, int last, int time)
{
	int		j;
	int		res;
	int		tmp;

	if (i == g_N)
		return (time);
	j = 0;
	res = 2147483647;
	while (++j < g_N + 1)
	{
		if (g_use[j] || g_X[last][j])
			continue ;
		g_use[j] = true;
		tmp = rec(i + 1, j, time + g_A[j][i]);
		if (tmp != -1)
			res = min(res, tmp);
		g_use[j] = false;
	}
	if (res == 2147483647)
		res = -1;
	return (res);
}

int	main(void)
{
	int	i;
	int	j;
	int	x;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
	{
		j = -1;
		while (++j < g_N)
			scanf("%d", &g_A[i + 1][j]);
	}
	scanf("%d", &g_M);
	i = -1;
	while (++i < g_M)
	{
		scanf("%d %d", &j, &x);
		g_X[j][x] = true;
		g_X[x][j] = true;
	}
	printf("%d\n", rec(0, 0, 0));
}
