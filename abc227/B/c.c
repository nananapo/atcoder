#include <stdio.h>

static int	g_N;
static int	g_S[21];

// 4ab + 3a + 3b = n
// 4Ab + 3b = n - 3a
// b(4A + 3) = n - 3a
// b = (n - 3a) / (4A + 3)
int	is_valid(int n)
{
	int	a;
	int	b;

	a = n / 2;
	while (--a > 0)
	{
		b = (n - 3 * a) / (4 * a + 3);
		if (b > 0 && 4 * a * b + 3 * a + 3 * b == n)
			return (1);
	}
	return (0);
}

int	main(void)
{
	int	i;
	int	result;

	scanf("%d", &g_N);
	i = -1;
	result = 0;
	while (++i < g_N)
	{
		scanf("%d", g_S + i);
		result += !is_valid(g_S[i]);
	}
	printf("%d\n", result);
}
