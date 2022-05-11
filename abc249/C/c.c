#include <stdio.h>
#include <string.h>

#define N_MAX 16
#define S_MAX 27

static int	g_N;
static int	g_K;
static char	g_S[N_MAX][S_MAX];
static int	g_state[N_MAX];
static int	g_count[N_MAX][26];

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	calc(int *state)
{
	int	i;
	int	j;
	int	result;
	int	count;

	i = -1;
	result = 0;
	while (++i < 26)
	{
		j = -1;
		count = 0;
		while (++j < g_N)
			count += g_count[j][i] && state[j];
		if (count == g_K)
			result += 1;
	}
	return (result);
}

int	rec(int	i, int *state)
{
	int	result;

	if (i == g_N)
		return (calc(state));
	result = rec(i + 1, state);
	state[i] = 1;
	result = max(result, rec(i + 1, state));
	state[i] = 0;
	return (result);
}

int	main(void)
{
	int	i;
	int	j;
	int	len;

	scanf("%d %d%*c", &g_N, &g_K);
	i = -1;
	while (++i < g_N)
		scanf("%s", g_S[i]);
	i = -1;
	while (++i < g_N)
	{
		len = strlen(g_S[i]);
		j = -1;
		while (++j < len)
			g_count[i][g_S[i][j] - 'a'] = 1;
	}
	printf("%d\n", rec(0, g_state));
}
