#include <stdio.h>

#define W_MAX 5 * 100050

static int	g_W;
static int	g_N;
static int	g_A[W_MAX];

void	stack(int L, int R)
{
}

int	main(void)
{
	int	i;
	int	l;
	int	r;

	scanf("%d%d", &g_W, &g_N);
	i = -1;
	while (++i < g_N)
	{
		scanf("%d%d", &l, &r);
		stack(l, r);
	}
	i = -1;
	while (++i < g_W)
		printf("%d\n", g_A[i]);
}
