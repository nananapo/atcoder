#include <stdio.h>

int	g_now[4];

int	main(void)
{
	int	N;
	int	i;
	int	P;
	int	j;
	int	A;

	P = 0;
	scanf("%d", &N);
	i = -1;
	while (++i < N)
	{
		scanf("%d", &A);
		g_now[0] = 1;
		j = 4;
		while (--j >= 0)
		{
			if (j + A >= 4)
				P += g_now[j];
			else
				g_now[j + A] = g_now[j];
			g_now[j] = 0;
		}
	}
	printf("%d\n", P);
}
