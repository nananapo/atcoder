#include <stdio.h>

static int	g_N;
static int	g_Q;
static int	g_A[200005];

int	cmpint(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void	bloop(int *left, int *length, int x)
{
	int	mid;

	mid = *left + *length / 2;
	if (*length == 2)
	{
		if (g_A[*left] < x)
			*left = *left + 1;
		*length = 1;
	}
	if (g_A[mid] < x)
	{
		*left = mid + 1;
		if (*length % 2 == 0)
			*length = *length / 2 - 1;
		else
			*length = *length / 2;
	}
	else
		*length = *length / 2 + 1;
}

// 1 2 3 4 5 6
void	query(int x)
{
	int	left;
	int	length;

	left = 0;
	length = g_N;
	if (g_A[length - 1] < x)
	{
		printf("0\n");
		return ;
	}
	while (length > 1)
		bloop(&left, &length, x);
	printf("%d\n", g_N - left);
}

int	main(void)
{
	int	i;
	int	x;

	scanf("%d %d", &g_N, &g_Q);
	i = -1;
	while (++i < g_N)
		scanf("%d", g_A + i);
	qsort(g_A, g_N, sizeof(int), cmpint);
	i = -1;
	while (++i < g_Q)
	{
		scanf("%d", &x);
		query(x);
	}
}
