#include <stdio.h>

#define N_MAX 1000

static int	g_A[N_MAX];
static int	g_B[N_MAX];

int	main(void)
{
	int	i;
	int	j;
	int	N;

	scanf("%d", &N);
	j = 0;
	while (++j < N + 1)
	{
		i = -1;
		while (++i < j)
		{
			if (i == 0 || i == j - 1)
				g_B[i] = 1;
			else
				g_B[i] = g_A[i - 1] + g_A[i];
		}
		i = -1;
		while (++i < j)
		{
			if (i != 0)
				printf(" ");
			printf("%d", g_B[i]);
			g_A[i] = g_B[i];
		}
		printf("\n");
	}
}
