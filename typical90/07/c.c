#include <stdio.h>
#include <stdlib.h>

int	g_N;
int	g_A[300001];
int	g_Q;

int	abs(int	x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	binloop(int b, int mid, int *left, int *length)
{
	if (g_A[mid] < b)
	{
		*left = mid;
		if (*length % 2 == 1)
			*length = *length / 2 + 1;
		else
			*length = *length / 2;
	}
	else
		*length = *length / 2 + 1;
}

void	put_answer(int b)
{
	int	left;
	int	mid;
	int	length;

	left = 0;
	length = g_N;
	while (length > 1)
	{
		mid = left + length / 2;
		if (g_A[mid] == b)
		{
			left = mid;
			break ;
		}
		if (length == 2)
		{
			if (abs(b - g_A[left]) > abs(b - g_A[left + 1]))
				left += 1;
			break ;
		}
		binloop(b, mid, &left, &length);
	}
	printf("%d\n", abs(b - g_A[left]));
}

int	cmp(const void *n1, const void *n2)
{
	return (*(int *)n1 - *(int *)n2);
}

int	main(void)
{
	int	i;
	int	b;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
		scanf("%d", &g_A[i]);
	scanf("%d", &g_Q);
	qsort(g_A, g_N, sizeof(int), cmp);
	i = -1;
	while (++i < g_Q)
	{
		scanf("%d", &b);
		put_answer(b);
	}
}
