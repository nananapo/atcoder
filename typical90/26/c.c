#include <stdio.h>
#include <stdlib.h>

#define N_MAX 101000

typedef struct s_road
{
	int				to;
	struct s_road	*next;
}	t_road;

static int		g_N;
static t_road	*g_R[N_MAX];

static int		g_color[N_MAX];
static int		g_red;

void	colorlize(int i, int is_red)
{
	t_road	*tmp;

	if (g_color[i] != 0)
		return ;
	g_color[i] = is_red + 1;
	g_red += is_red;
	tmp = g_R[i];
	while (tmp != NULL)
	{
		colorlize(tmp->to, !is_red);
		tmp = tmp->next;
	}
}

void	answer(void)
{
	int	i;
	int	is_red;
	int	last;
	int	out;

	is_red = (g_red > g_N - g_red) + 1;
	i = 0;
	last = -1;
	out = 0;
	while (++i <= g_N)
	{
		if (g_color[i] == is_red)
		{
			if (last != -1)
				printf(" ");
			printf("%d", i);
			last = i;
			if (++out == g_N / 2)
				return ;
		}
	}
}

int	main(void)
{
	int		i;
	int		A;
	int		B;
	t_road	*road;

	scanf("%d", &g_N);
	i = 0;
	while (++i < g_N)
	{
		scanf("%d %d", &A, &B);
		road = malloc(sizeof(t_road));
		road->to = B;
		road->next = g_R[A];
		g_R[A] = road;
		road = malloc(sizeof(t_road));
		road->to = A;
		road->next = g_R[B];
		g_R[B] = road;
	}
	colorlize(1, 0);
	answer();
}
