#include <stdio.h>
#include <stdlib.h>

static int	g_N;
static int	g_K;
static int	g_A[200005];
static int	g_B[200005];

void	answer(void)
{
	int	c;
	int	i;
	int	tmp;

	c = 1 + 2 + 4 + 8;
	i = 0;
	while (++i < g_N)
	{
		tmp = (abs(g_A[i] - g_A[i - 1]) <= g_K)
			+ (abs(g_B[i] - g_A[i - 1]) <= g_K) * 2
			+ (abs(g_A[i] - g_B[i - 1]) <= g_K) * 4
			+ (abs(g_B[i] - g_B[i - 1]) <= g_K) * 8;
		if (!((c & 5) && (tmp & 3)) && !((c & 10) && (tmp & 12)))
		{
			printf("No\n");
			return ;
		}
		if (!(c & 5))
			tmp = tmp & 12;
		if (!(c & 10))
			tmp = tmp & 3;
		c = tmp;
	}
	printf("Yes\n");
}

int	main(void)
{
	int	i;

	scanf("%d %d", &g_N, &g_K);
	i = -1;
	while (++i < g_N)
		scanf("%d", g_A + i);
	i = -1;
	while (++i < g_N)
		scanf("%d", g_B + i);
	answer();
}
