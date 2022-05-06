#include <stdio.h>
#include <string.h>

int		g_K;
int		g_N;
char	g_S[2 * 101000];

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	solve(void)
{
	int	left;
	int	right;
	int	result;

	left = 0;
	right = 0;
	result = 0;
	while (right < g_N)
	{
		if (g_S[right] == '.')
		{
			if (g_K == 0)
				while (g_S[left++] != '.')
					continue ;
			else
				g_K--;
			result = max(result, right - left + 1);
		}
		else
			result = max(result, right - left + 1);
		right++;
	}
	return (result);
}

int	main(void)
{
	scanf("%s", g_S);
	scanf("%d", &g_K);
	g_N = strlen(g_S);
	printf("%d\n", solve());
}
