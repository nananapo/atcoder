#include <stdio.h>
#include <math.h>

#define N_MAX 1100
#define LL long long

static int	g_N;
static int	g_K;

static int	g_A[N_MAX];
static int	g_X[N_MAX];
static int	g_Y[N_MAX];

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	solve(void)
{
	int	i;
	int	j;
	int	f;
	int	d;
	int	f2;
	int	d2;
	int	current;
	int	now;
	int	now2;
	int	aindex;

	i = -1;
	aindex = 0;
	current = 0;
	while (++i < g_N)
	{
		if (aindex < g_K && g_A[aindex] == i + 1)
		{
			aindex += 1;
			continue ;
		}
		j = -1;
		now2 = 1000000;
		while (++j < g_K)
		{
			now = abs(g_X[i] - g_X[g_A[j] - 1])
				+ abs(g_Y[i] - g_Y[g_A[j] - 1]);
			if (now < now2)
			{
				f2 = i;
				d2 = g_A[j] - 1;
				now2 = now;
			}
		}
		if (now2 > current)
		{
			current = now2;
			f = f2;
			d = d2;
		}
	}
	return sqrt((LL)(g_X[f] - g_X[d]) * (LL)(g_X[f] - g_X[d])
		+ (LL)(g_Y[f] - g_Y[d]) * (LL)(g_Y[f] - g_Y[d]));
}

int	main(void)
{
	int	i;

	scanf("%d %d", &g_N, &g_K);
	i = -1;
	while (++i < g_K)
		scanf("%d", g_A + i);
	i = -1;
	while (++i < g_N)
		scanf("%d %d", g_X + i , g_Y + i);
	printf("%.16lf", solve());
}
