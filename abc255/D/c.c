#include <stdio.h>

#define N_MAX 200200
#define LL long long

static int	g_N;
static int	g_Q;
static LL	g_A[N_MAX];

LL	absl(LL n)
{
	if (n < 0)
		return (-n);
	return (n);
}

LL	solve(LL q)
{
	int	i;
	LL	r;

	i = -1;
	r = 0;
	while (++i < g_N)
		r += absl(g_A[i] - q);
	return (r);
}

int	main(void)
{
	int	i;
	LL	q;

	scanf("%d %d", &g_N, &g_Q);
	i = -1;
	while (++i < g_N)
		scanf("%lld", g_A + i);
	i = -1;
	while (++i < g_Q)
	{
		scanf("%lld", &q);
		printf("%lld\n", solve(q));
	}
}
