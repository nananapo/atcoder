#include <stdio.h>

int	main(void)
{
	int	A;
	int	B;
	int	C;
	int	V;

	scanf("%d %d %d %d", &V, &A, &B, &C);
	V = V % (A + B + C);
	if (V < A)
		printf("F\n");
	else if (V < A + B)
		printf("M\n");
	else
		printf("T\n");
}
