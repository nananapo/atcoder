#include <stdio.h>

int	main(void)
{
	int	i;
	int	A;
	int	B;

	scanf("%d %d", &A, &B);
	i = -1;
	while (++i < 256)
	{
		if ((A ^ i) == B)
		{
			printf("%d\n", i);
			return (0);
		}
	}
}
