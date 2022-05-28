#include <stdio.h>

#define LL long long

static int	g_N;
static int	g_M;
static int	g_K;
static LL	g_dp[1050][5050];

void	answer(void)
{
	int	i;
	LL	a;

	i = 0;
	a = 0;
	while (++i < g_M + 1)
		a = (a + g_dp[g_N - 1][i]) % 998244353;
	printf("%lld\n", a);
}

void	loop(int i)
{
	int	j;
	LL	ac;
	int	k;

	ac = 0;
	j = g_K;
	while (++j < g_M + 1)
		ac = (ac + g_dp[i - 1][j]) % 998244353;
	j = 0;
	while (++j < g_M + 1)
	{
		g_dp[i][j] = ac;
		k = j + 1;
		if (k - g_K >= 1)
			ac = (ac + g_dp[i - 1][k - g_K]) % 998244353;
		if (k + g_K <= g_M + 1)
			ac = (ac - g_dp[i - 1][k + g_K - 1]) % 998244353;
	}
}

int	main(void)
{
	int	i;

	scanf("%d %d %d", &g_N, &g_M, &g_K);
	i = 0;
	while (++i < g_M + 1)
		g_dp[0][i] = 1;
	i = 0;
	while (++i < g_N)
		loop(i);
	answer();
}
