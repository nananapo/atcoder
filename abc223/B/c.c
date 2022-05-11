#include <stdio.h>
#include <string.h>

#define S_MAX 1010

static char	g_S[S_MAX * 2];
static int	g_len;

char	*get_min(void)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = g_S;
	while (++i < g_len)
	{
		if (strncmp(g_S + i, tmp, g_len) < 0)
			tmp = g_S + i;
	}
	return (tmp);
}

char	*get_max(void)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = g_S;
	while (++i < g_len)
	{
		if (strncmp(g_S + i, tmp, g_len) > 0)
			tmp = g_S + i;
	}
	return (tmp);
}

int	main(void)
{
	int		i;
	char	tmp[S_MAX];

	scanf("%s", tmp);
	g_len = strlen(tmp);
	strcat(g_S, tmp);
	strcat(g_S, tmp);
	printf("%s\n", strndup(get_min(), g_len));
	printf("%s\n", strndup(get_max(), g_len));
}
