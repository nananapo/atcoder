#include <stdio.h>

#define N_MAX 201000
#define LL long long

static int	g_N;
static int	g_A[N_MAX];
static int	g_M;
static int	g_B[N_MAX];
static int	g_count[N_MAX];
static int	g_first[N_MAX];

int	cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

LL	solve(void)
{
	int	i;
	LL	answer;

	answer = 0;
	i = 0;
	while (++i < g_M - 1)
	{
		answer += (LL)g_count[g_B[i]] * (LL)(g_first[g_B[i]])
			* (LL)(g_N - g_first[g_B[i + 1]]);
	}
	return (answer);
}

int	main(void)
{
	int	i;
	int	j;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
		scanf("%d", g_A + i);
	qsort(g_A, g_N, sizeof(int), cmp);
	i = -1;
	j = -1;
	while (++i < g_N)
	{
		if (j == -1 || g_A[i] != g_B[j])
			g_B[++j] = g_A[i];
		if (g_count[g_A[i]] == 0)
			g_first[g_A[i]] = i;
		g_count[g_A[i]]++;
	}
	g_M = j + 1;
	printf("%lld\n", solve());
}
