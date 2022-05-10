#include <stdio.h>

#define N_MAX 10100

#define LL long long

static LL	g_N;
static LL	g_M;
static LL	g_B[N_MAX][N_MAX];

int	validate(void)
{
	LL	i;
	LL	j;
	LL	basei;
	LL	basej;

	basei = g_B[0][0] / 7;
	basej = g_B[0][0] % 7;
	if (7 - basej < g_M)
		return (0);
	i = -1;
	while (++i < g_N)
	{
		j = -1;
		while (++j < g_M)
		{
			if (basej + j > 6)
				return (0);
			if (g_B[i][j] != (basei + i) * 7 + basej + j)
				return (0);
		}
	}
	return (1);
}

int	main(void)
{
	LL	i;
	LL	j;

	scanf("%lld %lld", &g_N, &g_M);
	i = -1;
	while (++i < g_N)
	{
		j = -1;
		while (++j < g_M)
		{
			scanf("%lld", g_B[i] + j);
			g_B[i][j]--;
		}
	}
	if (validate())
		printf("Yes\n");
	else
		printf("No\n");
}
