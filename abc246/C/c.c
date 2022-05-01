#include <stdio.h>
#include <stdlib.h>

static int	g_N;
static int	g_K;
static int	g_X;

#define ll long long

int	cmp(const void *a, const void *b)
{
	int	x;
	int	y;

	x = (*(int *)a) % g_X;
	y = (*(int *)b) % g_X;
	return (x - y);
}

ll	sum(int	*list, int size)
{
	ll	s;

	s = 0;
	while (size-- > 0)
		s += list[size];
	return (s);
}

int	main(void)
{
	int	A[200001];
	int	i;
	int	k;

	scanf("%d %d %d", &g_N, &g_K, &g_X);
	i = -1;
	while (++i < g_N)
		scanf("%d", &A[i]);
	i = -1;
	while (++i < g_N && g_K > 0)
	{
		k = A[i] / g_X;
		if (k > g_K)
			k = g_K;
		g_K -= k;
		A[i] = A[i] - k * g_X;
	}
	qsort(A, g_N, sizeof(int), cmp);
	i = g_N;
	while (i-- > 0 && g_K-- > 0)
		A[i] = 0;
	printf("%lld\n", sum(A, g_N));
}
