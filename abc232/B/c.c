#include <stdio.h>

int	main(void)
{
	char	S[100005];
	char	T[100005];
	int		i;
	int		j;

	scanf("%s", S);
	scanf("%s", T);
	i = -1;
	while (++i < 27)
	{
		j = 0;
		while (S[j] != '\0' && S[j] == (T[j] - 'a' + i) % 26 + 'a')
			j++;
		if (S[j] == '\0')
		{
			printf("Yes\n");
			return (0);
		}
	}
	printf("No\n");
}
