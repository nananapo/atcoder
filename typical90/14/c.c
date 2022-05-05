#include <stdio.h>
#include <stdlib.h>

#define LL long long

int	cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	main(void)
{
	int	N;
	int	A[100001];
	int	B[100001];
	int	i;
	LL	s;

	scanf("%d", &N);
	i = -1;
	while (++i < N)
		scanf("%d", A + i);
	i = -1;
	while (++i < N)
		scanf("%d", B + i);
	qsort(A, N, sizeof(int), cmp);
	qsort(B, N, sizeof(int), cmp);
	i = -1;
	s = 0;
	while (++i < N)
		s += abs(A[i] - B[i]);
	printf("%lld\n", s);
}
