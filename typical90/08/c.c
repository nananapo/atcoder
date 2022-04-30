#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		g_N;
char	g_S[100001];
int		*g_dp[100000];
int		g_dp_size = 0;

char	*g_seed = "atcoder";

int	*copy(int index)
{
	int	i;
	int	*line;

	line = (int *)malloc(sizeof(int) * 8);
	i = -1;
	while (++i < 9)
		line[i] = g_dp[index][i];
	return (line);
}

int	main(void)
{
	int		i;
	char	*c;
	int		*line;

	scanf("%d", &g_N);
	scanf("%s", g_S);
	g_dp[0] = (int *)calloc(8, sizeof(int));
	g_dp[0][0] = 1;
	i = -1;
	while (++i < g_N)
	{
		c = strchr(g_seed, g_S[i]);
		if (c == NULL)
			continue ;
		line = copy(g_dp_size);
		line[(c - g_seed) + 1] += g_dp[g_dp_size][c - g_seed];
		line[(c - g_seed) + 1] %= 1000000007;
		g_dp[++g_dp_size] = line;
	}
	printf("%d\n", g_dp[g_dp_size][7]);
}
