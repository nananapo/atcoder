#include <stdio.h>
#include <string.h>

int	g_H;
int	g_W;
int	g_A[2001][2001];
int	g_SH[2001];
int	g_SW[2001];

void	input(void)
{
	int	i;
	int	j;

	scanf("%d %d", &g_H, &g_W);
	i = -1;
	while (++i < g_H)
	{
		j = -1;
		while (++j < g_W)
			scanf("%d", &g_A[i][j]);
	}
}

void	calc_sum(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_H)
	{
		j = -1;
		g_SW[i] = 0;
		while (++j < g_W)
			g_SW[i] += g_A[i][j];
	}
	i = -1;
	while (++i < g_W)
	{
		j = -1;
		g_SH[i] = 0;
		while (++j < g_H)
			g_SH[i] += g_A[j][i];
	}
}

int	main(void)
{
	int	i;
	int	j;

	input();
	calc_sum();
	i = -1;
	while (++i < g_H)
	{
		j = -1;
		while (++j < g_W)
		{
			printf("%d", g_SW[i] + g_SH[j] - g_A[i][j]);
			if (j + 1 < g_W)
				printf(" ");
		}
		printf("\n");
	}
}
