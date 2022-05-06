#include <stdio.h>
#include <stdlib.h>

#define LL long long

static int		g_N;
static int		g_W;

typedef struct s_pair
{
	LL	fst;
	LL	snd;
}	t_pair;

static t_pair	*g_cheese[3 * 100005];

void	read_pair(int index)
{
	int		A;
	int		B;
	t_pair	*p;

	scanf("%d %d", &A, &B);
	p = (t_pair *)malloc(sizeof(t_pair));
	p->fst = (LL)A;
	p->snd = (LL)B;
	g_cheese[index] = p;
}

int	cmp(const void *a, const void *b)
{
	t_pair	*x;
	t_pair	*y;
	LL		diff;

	x = *(t_pair **)a;
	y = *(t_pair **)b;
	diff = y->fst - x->fst;
	if (diff > 0)
		return (1);
	if (diff < 0)
		return (-1);
	return (0);
}

void	solve(void)
{
	LL	result;
	int	index;

	index = -1;
	result = 0;
	while (++index < g_N && g_W > 0)
	{
		if (g_cheese[index]->snd >= g_W)
		{
			result += g_cheese[index]->fst * g_W;
			break ;
		}
		result += g_cheese[index]->fst * g_cheese[index]->snd;
		g_W -= g_cheese[index]->snd;
	}
	printf("%lld\n", result);
}

int	main(void)
{
	int	i;

	scanf("%d %d", &g_N, &g_W);
	i = -1;
	while (++i < g_N)
		read_pair(i);
	qsort(g_cheese, g_N, sizeof(t_pair *), cmp);
	solve();
}
