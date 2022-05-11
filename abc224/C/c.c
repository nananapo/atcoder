#include <stdio.h>

#define LL long long
#define N_MAX 305
static int	g_N;
static LL	g_X[N_MAX];
static LL	g_Y[N_MAX];

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	gcd(int a, int b)
{
	int	tmp;

	a = abs(a);
	b = abs(b);
	tmp = a;
	a = max(a, b);
	b = min(tmp, b);
	while (a % b != 0)
	{
		tmp = a;
		a = b;
		b = tmp % b;
	}
	return (b);
}

//y - dy = slope(x - dx);
int	is_valid(int i, int j, int k)
{
	int	dx;
	int	dy;
	int	tmp;

	dx = g_X[i] - g_X[j];
	dy = g_Y[i] - g_Y[j];
	if (dx == 0)
		return (g_X[i] != g_X[k]);
	if (dy == 0)
		return (g_Y[i] != g_Y[k]);
	tmp = gcd(dx, dy);
	dx /= tmp;
	dy /= tmp;
	if ((g_X[k] - g_X[i]) % dx == 0
		&& (g_Y[k] - g_Y[i]) % dy == 0
		&& (g_X[k] - g_X[i]) / dx == (g_Y[k] - g_Y[i]) / dy)
		return (0);
	return (1);
}

int	main(void)
{
	int	i;
	int	j;
	int	k;
	int	result;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
		scanf("%lld %lld", g_X + i, g_Y + i);
	result = 0;
	i = -1;
	while (++i < g_N - 2)
	{
		j = i;
		while (++j < g_N - 1)
		{
			k = j;
			while (++k < g_N)
				result += is_valid(i, j, k);
		}
	}
	printf("%d\n", result);
}
