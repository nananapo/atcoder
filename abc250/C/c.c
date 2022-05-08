#include <stdio.h>

#define N_MAX 202000

static int	g_NtoI[N_MAX];
static int	g_ItoN[N_MAX];

static int	g_N;
static int	g_Q;

void	answer(void)
{
	int	i;

	i = -1;
	while (++i < g_N)
	{
		if (i > 0)
			printf(" ");
		printf("%d", g_ItoN[i] + 1);
	}
	printf("\n");
}

void	move(int x)
{
	int	ix;
	int	y;

	ix = g_NtoI[x];
	y = g_ItoN[ix + 1];
	if (ix == g_N - 1)
		y = g_ItoN[ix - 1];
	g_NtoI[x] = ix + 1;
	if (ix == g_N - 1)
		g_NtoI[x] = ix - 1;
	g_NtoI[y] = ix;
	g_ItoN[ix] = y;
	if (ix == g_N - 1)
		g_ItoN[ix - 1] = x;
	else
		g_ItoN[ix + 1] = x;
}

int	main(void)
{
	int	i;
	int	x;

	scanf("%d %d", &g_N, &g_Q);
	i = -1;
	while (++i < g_N)
	{
		g_NtoI[i] = i;
		g_ItoN[i] = i;
	}
	i = -1;
	while (++i < g_Q)
	{
		scanf("%d", &x);
		move(x - 1);
	}
	answer();
}
