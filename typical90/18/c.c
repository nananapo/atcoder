#include <stdio.h>
#include <math.h>

static int		g_T;
static double	g_L;
static double	g_X;
static double	g_Y;
static double	g_Q;

void	resolve(int t)
{
	double	lx;
	double	ly;
	double	lz;
	double	tb;

	tb = (t % g_T) / (double)g_T * 2;
	lx = 0;
	ly = g_L / 2 * -sin(M_PI * tb);
	lz = g_L * (0.5 + sin(M_PI * (tb - 0.5)) / 2.0);
	tb = sqrt((lx - g_X) * (lx - g_X) + (ly - g_Y) * (ly - g_Y));
	tb = atan(lz / tb);
	printf("%.16lf\n", tb / M_PI * 180.0f);
}

int	main(void)
{
	int	i;
	int	t;

	scanf("%d %lf %lf %lf %lf", &g_T, &g_L, &g_X, &g_Y, &g_Q);
	i = -1;
	while (++i < g_Q)
	{
		scanf("%d", &t);
		resolve(t);
	}
}
