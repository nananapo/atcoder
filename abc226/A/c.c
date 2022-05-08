#include <stdio.h>

int	main(void)
{
	double	x;
	int		y;

	scanf("%lf", &x);
	y = (int)(x * 10) % 10;
	if (y % 10 > 4)
	{
		y = (int)(x * 10);
		printf("%d\n", y / 10 + 1);
	}
	else
	{
		y = (int)(x * 10);
		printf("%d\n", y / 10);
	}
}
