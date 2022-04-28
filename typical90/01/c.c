#include <stdio.h>
#include <stdbool.h>

#define ll long long

static int	g_N;
static ll	g_L;
static int	g_K;
static ll	g_A[100003];

bool	can_cut(ll n)
{
	ll	before;
	int	count;
	int	i;

	i = 0;
	before = 0;
	count = 0;
	while (i < g_N + 1)
	{
		if (g_A[i] - before >= n)
		{
			before = g_A[i];
			if (++count == g_K + 1)
				return (true);
		}
		i++;
	}
	return (false);
}

int	binary_search(ll left, ll length)
{
	ll	mid;

	while (length > 1)
	{
		mid = left + length / 2;
		if (can_cut(mid))
		{
			if (length % 2 == 0)
				length = length / 2;
			else
				length = length / 2 + 1;
			left = mid;
		}
		else
			length = length / 2;
	}
	return (left);
}

int	main(void)
{
	int	i;

	scanf("%d %lld", &g_N, &g_L);
	scanf("%d", &g_K);
	i = -1;
	while (++i < g_N)
		scanf("%lld", &g_A[i]);
	g_A[i] = g_L;
	printf("%d\n", binary_search(0, g_L));
}
