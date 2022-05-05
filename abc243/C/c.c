#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N_MAX 200200
#define B_SIZE 10007

typedef struct s_el
{
	int			x;
	int			y;
	struct s_el	*next;
}	t_el;

static int	g_N;
static int	g_X[N_MAX];
static int	g_Y[N_MAX];

static int	g_S[N_MAX];
static t_el	*g_DictR[B_SIZE];
static t_el	*g_DictL[B_SIZE];

bool	get_di(int y, int s, t_el **result);

bool	calc(void)
{
	int		i;
	t_el	*par;
	t_el	*tmp;

	i = -1;
	while (++i < B_SIZE)
	{
		par = g_DictR[i];
		while (par != NULL)
		{
			if (get_di(par->y, 0, &tmp))
				if (par->x <= tmp->x)
					return (true);
			par = par->next;
		}
	}
	return (false);
}

bool	get_di(int y, int s, t_el **result)
{
	t_el	*tmp;

	if (s)
		tmp = g_DictR[y % B_SIZE];
	else
		tmp = g_DictL[y % B_SIZE];
	while (tmp != NULL && tmp->y != y)
		tmp = tmp->next;
	if (tmp == NULL)
		return (false);
	*result = tmp;
	return (true);
}

void	update(int x, int y, int s)
{
	t_el	*el;

	if (get_di(y, s, &el))
	{
		if ((s && el->x > x) || (!s && el->x < x))
			el->x = x;
		return ;
	}
	el = (t_el *)malloc(sizeof(t_el));
	el->x = x;
	el->y = y;
	if (s)
	{
		el->next = g_DictR[y % B_SIZE];
		g_DictR[y % B_SIZE] = el;
	}
	else
	{
		el->next = g_DictL[y % B_SIZE];
		g_DictL[y % B_SIZE] = el;
	}
}

int	main(void)
{
	int		i;
	char	s[N_MAX];

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
		scanf("%d %d", g_X + i, g_Y + i);
	scanf("%s", s);
	i = -1;
	while (++i < g_N)
	{
		g_S[i] = s[i] == 'R';
		update(g_X[i], g_Y[i], g_S[i]);
	}
	if (calc())
		printf("Yes\n");
	else
		printf("No\n");
}
