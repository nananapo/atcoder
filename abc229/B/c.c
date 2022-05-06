#include <stdio.h>

#define LL long long

static LL	g_A;
static LL	g_B;

int	main(void)
{
	scanf("%lld %lld", &g_A, &g_B);
	while (g_A != 0 && g_B != 0)
	{
		if ((g_A % 10) + (g_B % 10) > 9)
		{
			printf("Hard\n");
			return (0);
		}
		g_A /= 10;
		g_B /= 10;
	}
	printf("Easy\n");
}
