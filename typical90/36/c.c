#include <stdio.h>
#include <stdlib.h>

#define N_MAX 100100
#define LL long long
#define LL_INF 922337203685477
static int		g_N;
static int		g_Q;

static LL		g_X[N_MAX];
static LL		g_Y[N_MAX];

static LL	g_minx;
static LL	g_maxx;
static LL	g_miny;
static LL	g_maxy;

LL	min(LL a, LL b)
{
	if (a < b)
		return (a);
	return (b);
}

LL	max(LL a, LL b)
{
	if (a < b)
		return (b);
	return (a);
}

LL	solve(int q)
{
	LL	X;
	LL	Y;
	LL	res;

	X = g_X[q] - g_Y[q];
	Y = g_X[q] + g_Y[q];
	res = 0;
	res = max(res, llabs(g_minx - X));
	res = max(res, llabs(g_maxx - X));
	res = max(res, llabs(g_miny - Y));
	res = max(res, llabs(g_maxy - Y));
	return (res);
}

int	main(void)
{
	int	i;
	int	q;

	scanf("%d%d", &g_N, &g_Q);
	i = -1;
	g_minx = LL_INF;
	g_miny = LL_INF;
	g_maxx = -LL_INF;
	g_maxy = -LL_INF;
	while (++i < g_N)
	{
		scanf("%lld%lld", g_X + i, g_Y + i);
		if (g_X[i] - g_Y[i] < g_minx) g_minx = g_X[i] - g_Y[i];
		if (g_X[i] - g_Y[i] > g_maxx) g_maxx = g_X[i] - g_Y[i];
		if (g_X[i] + g_Y[i] < g_miny) g_miny = g_X[i] + g_Y[i];
		if (g_X[i] + g_Y[i] > g_maxy) g_maxy = g_X[i] + g_Y[i];
	}
	i = -1;
	while (++i < g_Q)
	{
		scanf("%d", &q);
		printf("%lld\n", solve(q - 1));
	}
}
