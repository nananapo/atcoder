#include <stdio.h>
#define LL long long

static int	g_N;
static LL	g_A[101000];
static LL	g_X;
static LL	g_Acm[101000];

LL	solve(void)
{
	LL	r;
	int	i;

	r += (g_X / g_Acm[g_N]) * g_N;
	g_X = g_X % g_Acm[g_N];
	i = 0;
	while (g_X >= g_Acm[i++])
		r++;
	return (r);
}

int	main(void)
{
	int	i;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
		scanf("%lld", g_A + i);
	scanf("%lld", &g_X);
	g_Acm[0] = 0;
	i = -1;
	while (++i < g_N)
		g_Acm[i + 1] = g_Acm[i] + g_A[i];
	printf("%lld\n", solve());
}
