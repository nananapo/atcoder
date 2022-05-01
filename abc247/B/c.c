#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char	g_fam[101][11];
char	g_nam[101][11];

bool	allcmp(int N, int i)
{
	int	j;

	j = -1;
	while (++j < N)
	{
		if (i == j)
			continue ;
		if (strcmp(g_nam[i], g_nam[j]) == 0
			|| strcmp(g_nam[i], g_fam[j]) == 0)
		{	
			j = -1;
			while (++j < N)
			{
				if (i == j)
					continue ;
				if (strcmp(g_fam[i], g_nam[j]) == 0
					|| strcmp(g_fam[i], g_fam[j]) == 0)
					return (true);
			}
			return (false);
		}
	}
	return (false);
}

int	main(void)
{
	int	N;
	int	i;

	scanf("%d", &N);
	i = -1;
	while (++i < N)
		scanf("%s %s", g_fam[i], g_nam[i]);
	i = -1;
	while (++i < N)
	{
		if (allcmp(N, i))
		{
			printf("No\n");
			return (0);
		}
	}
	printf("Yes\n");
	return (0);
}
