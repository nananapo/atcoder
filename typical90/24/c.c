#include <stdio.h>

static int	g_N;
static int	g_K;

#define N_MAX 1100

static int	g_A[N_MAX];
static int	g_B[N_MAX];

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	main(void)
{
	int	i;
	int	sum;

	scanf("%d %d", &g_N, &g_K);
	i = -1;
	while (++i < g_N)
		scanf("%d", g_A + i);
	i = -1;
	while (++i < g_N)
		scanf("%d", g_B + i);
	sum = 0;
	i = -1;
	while (++i < g_N)
		sum += abs(g_A[i] - g_B[i]);
	if (sum > g_K)
		printf("No\n");
	else
	{
		if ((g_K - sum) % 2 == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
