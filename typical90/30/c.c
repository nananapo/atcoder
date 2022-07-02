#include <stdio.h>

#define N_MAX 10000100

static int	g_A[N_MAX];

int	main(void)
{
	int	N;
	int	K;
	int	i;
	int	j;

	g_A[1] = 1;
	scanf("%d%d", &N, &K);
	i = 1;
	while (++i <= N)
	{
		if (g_A[i] != 0)
			continue ;
		j = i;
		while (j <= N)
		{
			g_A[j] += 1;
			j += i;
		}
	}
	i = 1;
	j = 0;
	while (++i <= N)
		j += g_A[i] >= K;
	printf("%d\n", j);
}
