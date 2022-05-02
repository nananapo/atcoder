#include <stdio.h>

int	g_N;
int	g_x = 0;
int	g_y = 0;
int	g_dir = 1;

void	go_straight(void)
{
	if (g_dir == 0)
		g_y += 1;
	else if (g_dir == 1)
		g_x += 1;
	else if (g_dir == 2)
		g_y -= 1;
	else
		g_x -= 1;
}

int	main(void)
{
	char	S[100005];
	int		i;

	scanf("%d %s", &g_N, S);
	i = -1;
	while (++i < g_N)
	{
		if (S[i] == 'S')
			go_straight();
		else
			g_dir = (g_dir + 1) % 4;
	}
	printf("%d %d\n", g_x, g_y);
}
