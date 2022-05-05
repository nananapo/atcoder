#include <stdio.h>
#include <stdlib.h>

int	cmp(const void *a, const void *b)
{
	return (*((int *)a) - *((int *)b));
}

int	main(void)
{
	int	N;
	int	A[2005];
	int	i;
	int	now;

	scanf("%d", &N);
	i = -1;
	while (++i < N)
		scanf("%d", A + i);
	qsort(A, N, sizeof(int), cmp);
	i = -1;
	now = -1;
	while (++i < N)
	{
		if (A[i] - now >= 2)
			break ;
		now = A[i];
	}
	printf("%d\n", now + 1);
}
