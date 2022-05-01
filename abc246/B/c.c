#include <stdio.h>
#include <math.h>

int	main(void)
{
	float	A;
	float	B;
	float	rad;

	scanf("%f %f", &A, &B);
	if (A == 0)
	{
		if (B > 0)
			printf("0 1\n");
		else
			printf("0 -1\n");
		return (0);
	}
	rad = atan(B / A);
	printf("%f %f\n", cos(rad), sin(rad));
}
