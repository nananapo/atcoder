#include <stdio.h>
#include <stdlib.h>

static int	g_N;
static int	g_A;
static int	g_B;
static int	g_C;

static int	g_Q[3];

int	cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	fix(int a, int b, int c)
{
	g_Q[0] = a;
	g_Q[1] = b;
	g_Q[2] = c;
	qsort(g_Q, 3, sizeof(int), cmp);
	g_A = g_Q[2];
	g_B = g_Q[1];
	g_C = g_Q[0];
}

int	main(void)
{
	int	a;
	int	b;
	int	s;

	scanf("%d %d %d %d", &g_N, &g_A, &g_B, &g_C);
	fix(g_A, g_B, g_C);
	a = g_N / g_A;
	s = 100000000;
	while (a >= 0)
	{
		b = (g_N - a * g_A) / g_B;
		while (b >= 0)
		{
			if ((g_N - a * g_A - b * g_B) % g_C == 0)
				s = min(s, a + b + (g_N - a * g_A - b * g_B) / g_C);
			b--;
		}
		a--;
	}
	printf("%d\n", s);
}
