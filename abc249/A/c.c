#include <stdio.h>

static int	g_A;
static int	g_B;
static int	g_C;
static int	g_D;
static int	g_E;
static int	g_F;
static int	g_X;

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	calc(int a, int b, int c)
{
	int	i;
	int	result;

	i = g_X / (a + c);
	result = i * a * b
		+ b * min(g_X % (a + c), a);
	return (result);
}

int	main(void)
{
	int	t;
	int	a;

	scanf("%d %d %d %d %d %d %d", &g_A, &g_B, &g_C, &g_D, &g_E, &g_F, &g_X);
	t = calc(g_A, g_B, g_C);
	a = calc(g_D, g_E, g_F);
	if (a > t)
		printf("Aoki\n");
	else if (t > a)
		printf("Takahashi\n");
	else
		printf("Draw\n");
}
