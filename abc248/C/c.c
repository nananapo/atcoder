#include <stdio.h>
#include <stdlib.h>

#define LL long long

static int	g_N;
static int	g_M;
static int	g_K;

LL	answer(LL **dp)
{
	int	i;
	LL	s;

	i = -1;
	s = 0;
	while (++i <= g_K)
		s = (s + dp[g_N][i]) % 998244353;
	return (s);
}

void	dump(LL **dp)
{
	int	i;
	int	j;

	i = -1;
	printf("DUMP\n");
	while (++i <= g_K)
	{
		j = -1;
		while (++j <= g_N)
		{
			printf("%LLd ", dp[j][i]);
		}
		printf("\n");
	}
}

void	loop(int i, int j, LL **dp)
{
	int	k;
	int	to;

	k = j;
	to = j + g_M;
	while (k < g_K && k < to)
	{
		dp[i][k + 1] = dp[i][k + 1] + dp[i - 1][j];
		dp[i][k + 1] %= 998244353;
		k += 1;
	}
}

int	main(void)
{
	LL	*ptr;
	LL	**dp;
	int	i;
	int	j;

	scanf("%d %d %d", &g_N, &g_M, &g_K);
	ptr = (LL *)caLLoc((g_N + 1) * (g_K + 1), sizeof(LL));
	dp = (LL **)maLLoc((g_N + 1) * sizeof(LL *));
	i = -1;
	while (++i <= g_N)
		dp[i] = ptr + (g_K + 1) * i;
	dp[0][0] = 1;
	i = 0;
	while (++i <= g_N)
	{
		j = -1;
		while (++j <= g_K)
			loop(i, j, dp);
	}
	printf("%LLd\n", answer(dp));
}
