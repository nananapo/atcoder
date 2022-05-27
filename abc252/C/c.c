#include <stdio.h>
#include <string.h>

static int	g_N;
static char	g_S[1000][100];
static int	g_T[1000];
static int	g_played[1000];
static int	g_endc;

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	init(char t)
{
	int	i;

	i = -1;
	while (++i < g_N)
	{
		g_T[i] = strchr(g_S[i], t) - g_S[i];
		g_played[i] = 0;
	}
	g_endc = -1;
}

// 9 7 -> 2
// 4 7 -> 4 + 1   +  (9 - 7)
// 0 7 -> 0 + 1   +  (9 - 7)
int	next_time(int index, int offset)
{
	int	tmp;

	tmp = offset % 10;
	if (tmp == g_T[index])
		return (offset);
	if (tmp < g_T[index])
		return (offset + (g_T[index] - tmp));
	return (offset + (9 - tmp) + g_T[index] + 1);
}

int	solve(char t)
{
	int	i;
	int	offset;
	int	index;
	int	nt;

	init(t);
	offset = 0;
	while (++g_endc < g_N)
	{
		i = -1;
		index = 0;
		nt = 100000;
		while (++i < g_N)
		{
			if (g_played[i] == 0 && next_time(i, offset) < nt)
			{
				index = i;
				nt = next_time(i, offset);
			}
		}
		offset = next_time(index, offset) + 1;
		g_played[index] = 1;
	}
	return (offset - 1);
}

int	main(void)
{
	int	i;
	int	m;
	int	tmp;

	scanf("%d%*c", &g_N);
	i = -1;
	while (++i < g_N)
		scanf("%s", g_S[i]);
	i = -1;
	m = 1000000;
	while (++i < 10)
	{
		tmp = solve('0' + i);
		m = min(m, tmp);
	}
	printf("%d\n", m);
}
