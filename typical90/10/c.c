#include <stdio.h>

static int	g_N;
static int	g_acm1[100001];
static int	g_acm2[100001];

void	calc(void)
{
	int	c;
	int	p;
	int	i;

	i = -1;
	while (++i < g_N)
	{
		scanf("%d %d", &c, &p);
		if (c == 1)
		{
			g_acm1[i + 1] = g_acm1[i] + p;
			g_acm2[i + 1] = g_acm2[i];
		}
		else
		{
			g_acm1[i + 1] = g_acm1[i];
			g_acm2[i + 1] = g_acm2[i] + p;
		}
	}
}

int	main(void)
{
	int	i;
	int	Q;
	int	l;
	int	r;

	scanf("%d", &g_N);
	calc();
	scanf("%d", &Q);
	i = -1;
	while (++i < Q)
	{
		scanf("%d %d", &l, &r);
		printf("%d %d\n", g_acm1[r] - g_acm1[l - 1], g_acm2[r] - g_acm2[l - 1]);
	}
}
