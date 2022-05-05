#include <stdio.h>
#include <stdbool.h>

static int	g_N;
static int	g_M;

#define N_MAX 9

static bool	g_T[N_MAX][N_MAX];
static bool	g_A[N_MAX][N_MAX];
static bool	g_use[N_MAX];
static int	g_now[N_MAX];

bool	check(int *pair)
{
	int	i;
	int	j;

	i = 0;
	while (++i < N_MAX)
	{
		j = 0;
		while (++j < N_MAX)
			if (g_T[i][j] != g_A[pair[i - 1]][pair[j - 1]])
				return (false);
	}
	return (true);
}

bool	perm(int k, bool *use, int *now)
{
	int	i;

	if (k == g_N)
		return (check(now));
	i = 0;
	while (++i < N_MAX)
	{
		if (use[i])
			continue ;
		now[k] = i;
		use[i] = true;
		if (perm(k + 1, use, now))
			return (true);
		use[i] = false;
	}
	return (false);
}

int	main(void)
{
	int	a;
	int	b;
	int	i;

	scanf("%d %d", &g_N, &g_M);
	i = -1;
	while (++i < g_M)
	{
		scanf("%d %d", &a, &b);
		g_T[a][b] = true;
		g_T[b][a] = true;
	}
	i = -1;
	while (++i < g_M)
	{
		scanf("%d %d", &a, &b);
		g_A[a][b] = true;
		g_A[b][a] = true;
	}
	if (perm(0, g_use, g_now))
		printf("Yes\n");
	else
		printf("No\n");
}
