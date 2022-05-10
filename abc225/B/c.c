#include <stdio.h>

static int	g_p;
static int	g_p2;
static int	g_tmp;
static int	g_tmp2;

int	main(void)
{
	int	N;
	int	i;

	scanf("%d %d %d %d %d", &N, &g_p, &g_p2, &g_tmp, &g_tmp2);
	if (g_p == g_tmp || g_p == g_tmp2)
		g_p = g_p;
	else if (g_p2 == g_tmp || g_p2 == g_tmp2)
		g_p = g_p2;
	else
	{
		printf("No\n");
		return (0);
	}
	i = 1;
	while (++i < N - 1)
	{
		scanf("%d %d", &g_tmp, &g_tmp2);
		if (g_p != g_tmp && g_p != g_tmp2)
		{
			printf("No\n");
			return (0);
		}
	}
	printf("Yes\n");
}
