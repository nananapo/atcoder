#include <stdio.h>
#include <stdlib.h>

#define N_SIZE 200005

static int	g_N;
static int	g_A[N_SIZE];
static int	g_Q;

// それぞれの数字の出現数
static int	g_count[N_SIZE];
// 数字->indexの辞書
static int	*g_idx[N_SIZE];
// ユニークな数字の数
static int	g_unique_count = 0;

// tmp
static int	g_count_tmp[N_SIZE];

int	find_left(int *list, int length, int x)
{
	int	left;

	if (list[length - 1] < x)
		return (-1);
	left = 0;
	while (length > 1)
	{
		if (length == 2)
		{
			if (list[left] < x)
				left += 1;
			break ;
		}
		if (list[left + length / 2] >= x)
			length = length / 2 + 1;
		else
		{
			left = (left + length / 2) + 1;
			if (length % 2 == 1)
				length = length / 2;
			else
				length = length / 2 - 1;
		}
	}
	return (left);
}

int	find_right(int *list, int length, int x)
{
	int	left;

	if (list[0] > x)
		return (-1);
	left = 0;
	while (length > 1)
	{
		if (length == 2)
		{
			if (list[left + 1] <= x)
				left += 1;
			break ;
		}
		if (list[left + length / 2] <= x)
		{
			left = (left + length / 2);
			if (length % 2 == 1)
				length = length / 2 + 1;
			else
				length = length / 2;
		}
		else
			length = length / 2;
	}
	return (left);
}

void	loop(void)
{
	int	l;
	int	r;
	int	x;
	int	f;
	int	g;

	scanf("%d %d %d", &l, &r, &x);
	if (g_count[x] == 0)
		printf("0\n");
	else
	{
		f = find_left(g_idx[x], g_count[x], l - 1);
		g = find_right(g_idx[x], g_count[x], r - 1);
		if (f == -1 || g == -1 || g < f)
			printf("0\n");
		else
			printf("%d\n", g - f + 1);
	}
}

int	main(void)
{
	int	i;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
	{
		scanf("%d", g_A + i);
		if (g_count[g_A[i]] == 0)
			g_unique_count++;
		g_count[g_A[i]]++;
	}
	i = -1;
	while (++i < N_SIZE - 1)
		if (g_count[i] != 0)
			g_idx[i] = (int *)malloc(sizeof(int) * g_count[i]);
	i = -1;
	while (++i < g_N)
		g_idx[g_A[i]][g_count_tmp[g_A[i]]++] = i;
	scanf("%d", &g_Q);
	i = -1;
	while (++i < g_Q)
		loop();
}
