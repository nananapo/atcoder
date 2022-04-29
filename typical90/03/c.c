#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
static int		g_N;

typedef struct s_edge
{
	int				to;
	struct s_edge	*next;
}	t_edge;

#define SIZE 100002

static t_edge	*g_G[SIZE];

static int		g_nodes[SIZE];

static int		g_next[SIZE];

static bool		g_already[SIZE];

void	create_path(int A, int B)
{
	t_edge	*edge;

	edge = (t_edge *)malloc(sizeof(t_edge));
	edge->to = B;
	edge->next = g_G[A];
	g_G[A] = edge;
}

void	init_loop(void)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		g_already[i] = false;
		i++;
	}
	g_already[g_nodes[0]] = true;
	g_next[0] = -1;
}

void	loop(void)
{
	int		i;
	int		j;
	t_edge	*tmp;

	i = -1;
	j = 0;
	g_next[0] = -1;
	while (g_nodes[++i] != -1)
	{
		tmp = g_G[g_nodes[i]];
		while (tmp != NULL)
		{
			if (g_already[tmp->to] == false)
			{
				g_already[tmp->to] = true;
				g_next[j] = tmp->to;
				g_next[j++ + 1] = -1;
			}
			tmp = tmp->next;
		}
	}
}

int	search(void)
{
	int		i;
	int		j;
	t_edge	*tmp;
	int		result;

	init_loop();
	result = 0;
	while (true)
	{
		loop();
		if (g_next[0] == -1)
			break ;
		i = -1;
		while (g_next[++i] != -1)
			g_nodes[i] = g_next[i];
		g_nodes[i] = -1;
		result++;
	}
	return (result);
}

int	main(void)
{
	int	i;
	int	A;
	int	B;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
		g_G[i] = NULL;
	i = -1;
	while (++i < g_N - 1)
	{
		scanf("%d %d", &A, &B);
		create_path(A, B);
		create_path(B, A);
	}
	g_nodes[0] = 1;
	g_nodes[1] = -1;
	search();
	g_nodes[1] = -1;
	printf("%d\n", search() + 1);
}
