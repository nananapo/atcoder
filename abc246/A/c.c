#include <stdio.h>

int	g_x[3];
int	g_y[3];

int	get_only(int *list)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		c = 0;
		while (++j < 3)
			if (list[j] == list[i])
				c++;
		if (c == 1)
			return (list[i]);
	}
	return (-1);
}

int	main(void)
{
	scanf("%d %d\n%d %d\n%d %d", &g_x[0], &g_y[0], &g_x[1],
		&g_y[1], &g_x[2], &g_y[2]);
	printf("%d %d\n", get_only(g_x), get_only(g_y));
}
