#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int				index;
	struct s_list	*next;
}	t_list;

static int		g_N;
static int		g_K;
static char		g_S[100001];
static t_list	*g_D[26];
static t_list	*g_D_last[26];

void	create_elem(char c, int index)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	elem->index = index;
	elem->next = NULL;
	if (g_D_last[c - 'a'] == NULL)
		g_D[c - 'a'] = elem;
	else
		g_D_last[c - 'a']->next = elem;
	g_D_last[c - 'a'] = elem;
}

int	popnext(int c)
{
	int	now;

	now = g_D[c]->index;
	g_D[c] = g_D[c]->next;
	if (g_D[c] == NULL)
		g_D_last[c] = NULL;
	return (now);
}

void	next_char(int *now)
{
	int	j;
	int	found;
	int	p;

	j = -1;
	found = 0;
	while (++j < 26 && found == 0)
	{
		while (g_D[j] != NULL)
		{
			p = popnext(j);
			if (p > *now)
			{
				*now = p;
				found = 1;
				printf("%c", 'a' + j);
				break ;
			}
		}
	}
}

void	put_answer(void)
{
	int	i;
	int	now;
	int	ni;

	now = -1;
	i = -1;
	while (++i < g_K)
	{
		next_char(&now);
		ni = g_N - g_K + i + 1;
		if (ni != g_N)
			create_elem(g_S[ni], ni);
	}
	printf("\n");
}

int	main(void)
{
	int	i;

	scanf("%d %d", &g_N, &g_K);
	scanf("%s", g_S);
	i = -1;
	while (++i < g_N - g_K + 1)
		create_elem(g_S[i], i);
	put_answer();
}
