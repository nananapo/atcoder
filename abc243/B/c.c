#include <stdio.h>

#define N_MAX 1005

static int	g_N;
static int	g_A[N_MAX];
static int	g_B[N_MAX];

int	c1(void)
{
	int	i;
	int	r;

	r = 0;
	i = -1;
	while (++i < g_N)
		r = r + (g_A[i] == g_B[i]);
	return (r);
}

int	c2(void)
{
	int	i;
	int	j;
	int	r;

	i = -1;
	while (++i < g_N)
	{
		j = -1;
		while (++j < g_N)
			r = r + (g_A[i] == g_B[j] && i != j);
	}
	return (r);
}

int	main(void)
{
	int	i;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
		scanf("%d", g_A + i);
	i = -1;
	while (++i < g_N)
		scanf("%d", g_B + i);
	printf("%d\n%d\n", c1(), c2());
}
