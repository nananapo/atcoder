#include <stdio.h>

#define H_MAX 101
#define W_MAX 101

#define DEF_INIT -100
int		g_H;
int		g_W;
char	g_C[H_MAX + 1][W_MAX + 1];
int		g_dp[H_MAX][W_MAX];

void	init(void)
{
	int	h;
	int	w;

	h = -1;
	while (++h < g_H)
	{
		w = -1;
		while (++w < g_W)
		{
			if (g_C[h][w] == '.')
				g_dp[h][w] = DEF_INIT;
			else
				g_dp[h][w] = 0;
		}
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_dp(int h, int w)
{
	int	now;

	if (g_dp[h][w] != DEF_INIT)
		return (g_dp[h][w]);
	now = 1;
	if (h != g_H - 1)
		now = max(now, get_dp(h + 1, w) + 1);
	if (w != g_W - 1)
		now = max(now, get_dp(h, w + 1) + 1);
	g_dp[h][w] = now;
	return (now);
}

int	main(void)
{
	int	i;

	scanf("%d %d", &g_H, &g_W);
	i = -1;
	while (++i < g_H)
		scanf("%s", g_C[i]);
	init();
	printf("%d\n", get_dp(0, 0));
}
