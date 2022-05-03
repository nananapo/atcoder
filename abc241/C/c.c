#include <stdio.h>
#include <stdbool.h>

int		g_N;
char	g_S[1009][1009];
char	g_ST[1009][1009];

bool	line(char *s)
{
	int	i;
	int	sum;
	int	length;

	i = 0;
	sum = 0;
	length = g_N;
	while (i < 6 && i < length)
		sum += s[i++] == '#';
	if (sum >= 4)
		return (true);
	while (i < length)
	{
		sum = sum - (s[i - 6] == '#') + (s[i] == '#');
		if (sum >= 4)
			return (true);
		i++;
	}
	return (false);
}

bool	lt(int	index)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	if (index < 5)
		return (false);
	while (++i < 6)
		sum += g_S[index - i][i] == '#';
	if (sum >= 4)
		return (true);
	while (i <= index)
	{
		sum = sum - (g_S[index - i + 6][i - 6] == '#')
			 + (g_S[index - i][i] == '#');
		if (sum >= 4)
			return (true);
		i++;
	}
	return (false);
}

bool	dr(int	index)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	if (index >= g_N - 5)
		return (false);
	while (++i < 6)
		sum += g_S[g_N - i - 1][i + index] == '#';
	if (sum >= 4)
		return (true);
	while (i < g_N - index)
	{
		sum = sum - (g_S[g_N - i - 1 + 6][i + index - 6] == '#')
			 + (g_S[g_N - i - 1][i + index] == '#');
		if (sum >= 4)
			return (true);
		i++;
	}
	return (false);
}

bool	ld(int	index)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	if (index >= g_N - 5)
		return (false);
	while (++i < 6)
		sum += g_S[index + i][i] == '#';
	if (sum >= 4)
		return (true);
	while (i < g_N - index)
	{
		sum = sum - (g_S[index + i - 6][i - 6] == '#')
			 + (g_S[index + i][i] == '#');
		if (sum >= 4)
			return (true);
		i++;
	}
	return (false);
}

bool	tr(int	index)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	if (index >= g_N - 5)
		return (false);
	while (++i < 6)
		sum += g_S[i][index + i] == '#';
	if (sum >= 4)
		return (true);
	while (i < g_N - index)
	{
		sum = sum - (g_S[i - 6][index + i - 6] == '#')
			 + (g_S[i][index + i] == '#');
		if (sum >= 4)
			return (true);
		i++;
	}
	return (false);
}

int	main(void)
{
	int	i;
	int	j;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
	{
		scanf("%s", g_S[i]);
		j = -1;
		while (++j < g_N)
			g_ST[j][i] = g_S[i][j];
	}
	i = -1;
	while (++i < g_N)
	{
		if (line(g_S[i]) || line(g_ST[i]) || lt(i)
			|| dr(i) || ld(i) || tr(i))
		{
			printf("Yes\n");
			return (0);
		}
	}
	printf("No\n");
}
