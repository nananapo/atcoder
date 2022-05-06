#include <stdio.h>

static char	g_S[2][3];

int	main(void)
{
	int	i;

	scanf("%s", g_S[0]);
	scanf("%s", g_S[1]);
	i = (g_S[0][0] == '#') + (g_S[0][1] == '#')
		+ (g_S[1][0] == '#') + (g_S[1][1] == '#');
	if (i == 2
		&& ((g_S[0][0] == '#' && g_S[1][1] == '#')
			|| (g_S[0][1] == '#' && g_S[1][0] == '#')))
	{
		printf("No\n");
		return (0);
	}
	printf("Yes\n");
}
