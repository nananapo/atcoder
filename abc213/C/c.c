#include <stdio.h>
#include <stdlib.h>

#define N_MAX 101000

static int		g_H;
static int		g_W;
static int		g_N;

typedef struct s_pair
{
	int	num;
	int	y;
	int	x;
}	t_pair;

static t_pair	g_P[N_MAX];

int	cmpn(const void *a, const void *b)
{
	t_pair	*c;
	t_pair	*d;

	c = (t_pair *)a;
	d = (t_pair *)b;
	return (c->num - d->num);
}

int	cmpy(const void *a, const void *b)
{
	t_pair	*c;
	t_pair	*d;

	c = (t_pair *)a;
	d = (t_pair *)b;
	return (c->y - d->y);
}

int	cmpx(const void *a, const void *b)
{
	t_pair	*c;
	t_pair	*d;

	c = (t_pair *)a;
	d = (t_pair *)b;
	return (c->x - d->x);
}

void	order_vertical(void)
{
	int	i;
	int	lasty;
	int	y;

	qsort(g_P, g_N, sizeof(t_pair), cmpy);
	i = -1;
	lasty = 0;
	y = 0;
	while (++i < g_N)
	{
		if (lasty != g_P[i].y)
			y++;
		lasty = g_P[i].y;
		g_P[i].y = y;
	}
}

void	order_horizontal(void)
{
	int	i;
	int	lastx;
	int	x;

	qsort(g_P, g_N, sizeof(t_pair), cmpx);
	i = -1;
	lastx = 0;
	x = 0;
	while (++i < g_N)
	{
		if (lastx != g_P[i].x)
			x++;
		lastx = g_P[i].x;
		g_P[i].x = x;
	}
}

void	answer(void)
{
	int	i;

	qsort(g_P, g_N, sizeof(t_pair), cmpn);
	i = -1;
	while (++i < g_N)
		printf("%d %d\n", g_P[i].y, g_P[i].x);
}

int	main(void)
{
	int	i;
	int	a;
	int	b;

	scanf("%d %d %d", &g_H, &g_W, &g_N);
	i = -1;
	while (++i < g_N)
	{
		scanf("%d %d", &a, &b);
		g_P[i].num = i;
		g_P[i].y = a;
		g_P[i].x = b;
	}
	order_vertical();
	order_horizontal();
	answer();
}
