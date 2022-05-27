#include <stdio.h>
#include <stdlib.h>

static int	g_N;
static int	g_K;
static int	g_A[1000];
static int	g_B[1000];

typedef struct s_pair
{
	int	fst;
	int	snd;
}			t_p;

static t_p	*g_pairs[1000];

int	cmp(const void *a, const void *b)
{
	t_p	*c;
	t_p	*d;

	c = *(t_p **)a;
	d = *(t_p **)b;
	return (d->fst - c->fst);
}

void	create_pair(int index)
{
	g_pairs[index] = malloc(sizeof(t_p));
	g_pairs[index]->fst = g_A[index];
	g_pairs[index]->snd = 0;
}

void	answer(void)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (p == 0 && i < g_N && g_pairs[0]->fst == g_pairs[i]->fst)
	{
		if (g_pairs[i]->snd == 1)
			p = 1;
		i++;
	}
	if (p == 0)
		printf("No\n");
	else
		printf("Yes\n");
}

int	main(void)
{
	int	i;

	scanf("%d %d", &g_N, &g_K);
	i = -1;
	while (++i < g_N)
	{
		scanf("%d", g_A + i);
		create_pair(i);
	}
	i = -1;
	while (++i < g_K)
	{
		scanf("%d", g_B + i);
		g_pairs[g_B[i] - 1]->snd = 1;
	}
	qsort(g_pairs, g_N, sizeof(t_p *), cmp);
	answer();
}
