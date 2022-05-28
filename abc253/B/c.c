#include <stdio.h>

static int	g_H;
static int	g_W;
static char	g_S[1000][1000];

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	solve(void)
{
	int	i;
	int	j;
	int	pos1;
	int	pos2;

	i = -1;
	pos1 = -1;
	pos2 = -1;
	while (++i < g_H)
	{
		j = -1;
		while (++j < g_W)
		{
			if (g_S[i][j] == 'o' && pos1 == -1)
				pos1 = i * g_W + j;
			else if (g_S[i][j] == 'o')
				pos2 = i * g_W + j;
		}
	}
	printf("%d\n", abs(pos1 % g_W - pos2 % g_W) + abs(pos1 / g_W - pos2 / g_W));
}

int	main(void)
{
	int	i;

	scanf("%d %d%*c", &g_H, &g_W);
	i = -1;
	while (++i < g_H)
		scanf("%s", g_S[i]);
	solve();
}
