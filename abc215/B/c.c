#include <stdio.h>

int	main(void)
{
	long long	N;
	int			i;

	i = 0;
	scanf("%lld", &N);
	while (N >= 2)
	{
		i++;
		N /= 2;
	}
	printf("%d\n", i);
}
