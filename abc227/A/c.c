#include <stdio.h>

static int	g_N;
static int	g_K;
static int	g_A;

int	main(void)
{
	int	a;

	scanf("%d %d %d", &g_N, &g_K, &g_A);
	if (g_N == 1)
	{
		printf("1\n");
		return (0);
	}
	g_K = g_K % g_N;
	a = g_A + g_K - 1;
	if (a > g_N)
		a %= g_N;
	printf("%d\n", a);
}
