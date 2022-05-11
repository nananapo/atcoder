#include <stdio.h>
#include <string.h>

#define N_MAX 101000

static int	g_N;
static int	g_A[N_MAX];
static int	g_B[N_MAX];

double	get_answer(void)
{
	int		i;
	double	t;
	double	r;

	i = -1;
	while (++i < g_N)
		t += g_A[i] / (double)g_B[i];
	t /= 2;
	i = -1;
	r = 0;
	while (++i < g_N)
	{
		if (g_A[i] / (double)g_B[i] > t)
		{
			r += (double)g_B[i] * t;
			break ;
		}
		r += g_A[i];
		t -= g_A[i] / (double)g_B[i];
	}
	return (r);
}

int	main(void)
{
	int	i;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
		scanf("%d %d", g_A + i, g_B + i);
	printf("%lf", get_answer());
}
