#include <stddef.h>
#include <stdio.h>

static int	g_H;
static int	g_W;
static int	g_Q;

static int	g_t;
static int	g_r1;
static int	g_c1;
static int	g_r2;
static int	g_c2;

static int	g_is_red[4400005];
static int	g_uf_parent[4400005];

// unionの親を求める
// 親を再帰的に求めて、簡約する
int	uf_get_root(int n)
{
	int	root;

	if (g_uf_parent[n] == 0)
		return (n);
	root = uf_get_root(g_uf_parent[n]);
	if (root != n)
		g_uf_parent[n] = root;
	return (root);
}

// unionする
// 片方の親の親をもう片方にする
void	uf_union(int n1, int n2)
{
	n1 = uf_get_root(n1);
	n2 = uf_get_root(n2);
	if (n1 == n2)
		return ;
	g_uf_parent[n1] = n2;
}

void	add(int x, int y)
{
	int	index;

	index = y * g_W + x;
	g_is_red[index] = 1;
	if (x != 1 && g_is_red[index - 1])
		uf_union(index, index - 1);
	if (x != g_W && g_is_red[index + 1])
		uf_union(index, index + 1);
	if (y != 1 && g_is_red[index - g_W])
		uf_union(index, index - g_W);
	if (y != g_H && g_is_red[index + g_W])
		uf_union(index, index + g_W);
}

void	check(int x1, int y1, int x2, int y2)
{
	int	index1;
	int	index2;

	index1 = y1 * g_W + x1;
	index2 = y2 * g_W + x2;
	if (!g_is_red[index1] || !g_is_red[index2])
	{
		printf("No\n");
		return ;
	}
	if (uf_get_root(index1) == uf_get_root(index2))
		printf("Yes\n");
	else
		printf("No\n");
}

int	main(void)
{
	int	i;

	scanf("%d %d %d", &g_H, &g_W, &g_Q);
	i = -1;
	while (++i < g_Q)
	{
		scanf("%d", &g_t);
		if (g_t == 1)
		{
			scanf("%d %d", &g_r1, &g_c1);
			add(g_c1, g_r1);
		}
		else
		{
			scanf("%d %d %d %d", &g_r1, &g_c1, &g_r2, &g_c2);
			check(g_c1, g_r1, g_c2, g_r2);
		}
	}
}
