#include <stdio.h>
#include <stdlib.h>

#define N_MAX 2 * 100200

static int	g_N;
static int	g_K;
static int	g_A[N_MAX];
static int	g_B[N_MAX];

static int	g_U[N_MAX];

int	cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	check(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_N)
	{
		j = i;
		while (j < g_N)
		{
			if (g_A[j] == g_B[i])
				return 
			j += g_K;
		}
		if (j >= g_N)
			return (0);
	}
	return (1);
}

int	main(void)
{
	int	i;

	scanf("%d %d", &g_N, &g_K);
	i = -1;
	while (++i < g_N)
	{
		scanf("%d", g_A + i);
		g_B[i] = g_A[i];
	}
	qsort(g_B, g_N, sizeof(int), cmp);
	if (g_K == 1 || check())
		printf("Yes\n");
	else
		printf("No\n");
}
