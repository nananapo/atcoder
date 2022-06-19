#include <stdio.h>

static int	g_R;
static int	g_C;

int	main(void)
{
	int	A;
	int	B;
	int	C;
	int	D;

	scanf("%d%d%d%d%d%d", &g_R, &g_C, &A, &B, &C, &D);
	if (g_R == 1)
	{
		if (g_C == 1)
			printf("%d", A);
		else
			printf("%d", B);
	}
	else
	{
		if (g_C == 1)
			printf("%d", C);
		else
			printf("%d", D);
	}
}
