#include <stdio.h>

#define H_MAX 55

static int	g_H;
static int	g_W;
static int	g_A[H_MAX][H_MAX];

int	is_valid(int i, int j)
{
	int	n;
	int	m;

	n = i;
	while (++i < g_H)
	{
		m = j;
		while (++j < g_W)
		{
			if (g_A[i][j] + g_A[n][m] > g_A[n][j] + g_A[i][m])
				return (0);
		}
	}
	return (1);
}

int	main(void)
{
	int	i;
	int	j;

	scanf("%d %d", &g_H, &g_W);
	i = -1;
	while (++i < g_H)
	{
		j = -1;
		while (++j < g_W)
			scanf("%d", g_A[i] + j);
	}
	i = -1;
	while (++i < g_H)
	{
		j = -1;
		while (++j < g_W)
		{
			if (!is_valid(i, j))
			{
				printf("No\n");
				return (0);
			}
		}
	}
	printf("Yes\n");
}
