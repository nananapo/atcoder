#include <stdio.h>
#include <string.h>

static int	g_a[26];
static int	g_A[26];

int	get_flag(void)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (++i < 26)
	{
		if (g_a[i] > 1 || g_A[i] > 1)
			flag |= 4;
		if (g_a[i])
			flag |= 1;
		if (g_A[i])
			flag |= 2;
	}
	return (flag);
}

int	main(void)
{
	char	S[110];
	int		len;
	int		i;

	scanf("%s", S);
	len = strlen(S);
	i = -1;
	while (++i < len)
	{
		if (S[i] >= 'a')
			g_a[S[i] - 'a'] += 1;
		else
			g_A[S[i] - 'A'] += 1;
	}
	if (get_flag() == 3)
		printf("Yes\n");
	else
		printf("No\n");
}
