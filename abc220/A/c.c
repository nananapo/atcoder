#include <stdio.h>

int	main(void)
{
	int	A;
	int	B;
	int	C;
	int	r;

	scanf("%d %d %d", &A, &B, &C);
	r = (A + C - 1) / C * C;
	if (r > B)
		r = -1;
	printf("%d\n", r);
}
