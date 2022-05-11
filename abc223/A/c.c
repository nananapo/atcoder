#include <stdio.h>

int	main(void)
{
	int	N;

	scanf("%d", &N);
	if (N > 0 && N % 100 == 0)
		printf("Yes\n");
	else
		printf("No\n");
}
