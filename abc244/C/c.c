#include <stdio.h>
#include <stdbool.h>

static int	g_N;
static bool	g_is_used[2005];

int	main(void)
{
	int	last;
	int	aoki;

	scanf("%d", &g_N);
	last = -1;
	while (last < 2005)
		g_is_used[last++] = false;
	g_is_used[0] = true;
	last = 0;
	while (true)
	{
		while (g_is_used[last])
			last++;
		g_is_used[last] = true;
		printf("%d\n", last);
		fflush(stdout);
		scanf("%d", &aoki);
		g_is_used[aoki] = true;
		if (aoki == 0)
			return (0);
	}
}
