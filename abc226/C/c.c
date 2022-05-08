#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N_MAX 202000
#define LL long long

typedef struct s_list
{
	int				need;
	struct s_list	*next;
}	t_list;

static int		g_N;
static LL		g_T[N_MAX];
static int		g_K[N_MAX];
static t_list	*g_A[N_MAX];

static bool		g_obtained[N_MAX];
static LL		g_time = 0;

void	obtain(int target)
{
	t_list	*tmp;

	if (g_obtained[target])
		return ;
	tmp = g_A[target];
	while (tmp != NULL)
	{
		obtain(tmp->need);
		tmp = tmp->next;
	}
	g_time += g_T[target];
	g_obtained[target] = true;
	return ;
}

void	add_need(int index)
{
	int		need;
	t_list	*tmp;

	scanf("%d", &need);
	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->need = need;
	tmp->next = g_A[index];
	g_A[index] = tmp;
}

int	main(void)
{
	int	i;
	int	j;

	scanf("%d", &g_N);
	i = 0;
	while (++i < g_N + 1)
	{
		scanf("%lld %d", g_T + i, g_K + i);
		j = -1;
		while (++j < g_K[i])
			add_need(i);
	}
	obtain(g_N);
	printf("%lld\n", g_time);
}
