#include <stdio.h>

int	main(void)
{
	int	N;

	scanf("%d", &N);
	if (N % 100 < 10)
		printf("0%d\n", N % 100);
	else
		printf("%d\n", N % 100);
}
